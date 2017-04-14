cmake_minimum_required(VERSION 2.6)
project(functional_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -Wall -Wextra -Weffc++")

include_directories(include/)

add_executable(wc_imperative
    src/basics/wc_imperative.cpp)
add_executable(wc_functional
    src/basics/wc_functional.cpp)
add_executable(average
    src/basics/average.cpp)
add_executable(folding
    src/basics/folding.cpp)
add_executable(string_trimming
    src/basics/string_trimming.cpp)
add_executable(filtering_and_transforming
    src/basics/filtering_and_transforming.cpp)
add_executable(implementing_hof
    src/basics/implementing_hof.cpp)

add_executable(function_definition
    src/functional_objects/function_definition.cpp)
add_executable(functions
    src/functional_objects/functions.cpp)
add_executable(lambdas
    src/functional_objects/lambdas.cpp)
add_executable(lambda_internals
    src/functional_objects/company.cpp
    src/functional_objects/lambda_internals.cpp)
add_executable(mutable_lambda
    src/functional_objects/mutable_lambda.cpp)
