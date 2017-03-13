cmake_minimum_required(VERSION 2.6)
project(functional_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -Wall -Wextra -Weffc++")

include_directories(include/)

add_executable(wc_imperative
    src/basics/wc_imperative.cpp)
add_executable(wc_functional
    src/basics/wc_functional.cpp)
