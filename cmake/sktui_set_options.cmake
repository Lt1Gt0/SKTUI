find_program(CLANG_TIDY_EXE NAMES "clang-tidy" DOC "Path to clang-tidy executable")
if (NOT CLANG_TIDY_EXE)
    message(STATUS "clang-tidy not found")
else()
    message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
endif()

function(sktui_set_options library)
    set_target_properties(${library} PROPERTIES 
        VERSION ${PROJECT_VERSION}
        OUTPUT_NAME "sktui-${library}" 
    )

    if(CLANG_TIDY_EXE AND SKTUI_CLANG_TIDY)
        set_target_properties(${library}
            PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_EXE};-warnings-as-errors=*" 
        )

        target_include_directories(${library}
            PUBLIC 
                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> 
        )
    else()
        target_include_directories(${library} SYSTEM
            INTERFACE 
                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> 
        )
    endif()

    target_include_directories(${library} SYSTEM
        INTERFACE 
            $<INSTALL_INTERFACE:include> 
    )

    target_include_directories(${library} SYSTEM
        PRIVATE 
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src> 
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> 
    )

    target_compile_features(${library} PUBLIC cxx_std_17)

    if (NOT WIN32)
        target_compile_options(${library} PRIVATE "-Wall")
        target_compile_options(${library} PRIVATE "-Wextra")
        target_compile_options(${library} PRIVATE "-pedantic")
        target_compile_options(${library} PRIVATE "-Werror")
        target_compile_options(${library} PRIVATE "-Wmissing-declarations")
        target_compile_options(${library} PRIVATE "-Wdeprecated")
        target_compile_options(${library} PRIVATE "-Wshadow")
    endif()
endfunction()
