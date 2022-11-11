set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR})

function (test name)
    add_executable(sktui_test_${name} ${name}.cpp)
    target_link_libraries(sktui_test_${name} PUBLIC ${DIRECTORY_LIB})
    file(RELATIVE_PATH dir ${TEST_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
    set_property(GLOBAL APPEND PROPERTY SKTUI::TESTS ${dir}/${name})
    set_target_properties(sktui_test_${name} PROPERTIES 
        CXX_STANDARD 20 
    )
endfunction(test)

add_subdirectory(samples)
