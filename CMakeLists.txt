cmake_minimum_required(VERSION 3.10)
project(lab3)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(googletest)

add_library(util STATIC util/bisection.cpp)
target_include_directories(util PUBLIC util/)

add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE util gtest)

enable_testing()
add_test(NAME BisectionTests COMMAND tests)
