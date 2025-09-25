cmake_minimum_required(VERSION 3.10)
project(lab3)

add_subdirectory(Catch2)

add_library(util STATIC util/bisection.cpp)
target_include_directories(util PUBLIC util/)

add_executable(tests tests.cpp)

target_link_libraries(tests PRIVATE util Catch2::Catch2WithMain)

