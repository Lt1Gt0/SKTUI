cmake_minimum_required(VERSION 3.20)

project(sktui
    LANGUAGES CXX
    VERSION 3.0.0
)

option(SKTUI_ENABLE_COVERAGE "Code Coverage" ON)
option(SKTUI_CLANG_TIDY "clang-tidy enabled" ON)
option(SKTUI_BUILD_TESTS "Allowing test applications to be built" ON)
option(SKTUI_ENABLE_INSTALL "Allowing install" ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(terminal
    include/terminal/pixel.h

    src/terminal/pixel.cpp
)

find_package(Threads)
target_link_libraries(terminal
    PUBLIC Threads::Threads
)

include(cmake/sktui_set_options.cmake)
sktui_set_options(terminal)

include(cmake/sktui_coverage.cmake)
sktui_check_coverage(terminal)

if(SKTUI_BUILD_TESTS)
    add_subdirectory(tests)
endif()

include(cmake/iwyu.cmake)

if(SKTUI_ENABLE_INSTALL)
    include(cmake/sktui_install.cmake)
endif()
