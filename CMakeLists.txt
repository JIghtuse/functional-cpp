cmake_minimum_required(VERSION 2.10)
project(functional_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -Wall -Wextra -Weffc++")

include_directories(include/)

find_package(Boost 1.60)
if (Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()

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
add_executable(filter_less_boilerplate
    src/functional_objects/filter_less_boilerplate.cpp)
add_executable(stl_operator_function_objects
    src/functional_objects/stl_operator_function_objects.cpp)
add_executable(boost_phoenix_operator_function_objects
    src/functional_objects/boost_phoenix_operator_function_objects.cpp)
add_executable(wrapping_with_std_function
    src/functional_objects/wrapping_with_std_function.cpp)

add_executable(partial_function_application
    src/new_functions/partial_function_application.cpp)
add_executable(bind
    src/new_functions/bind.cpp)
add_executable(lambdas_as_bind_alternative
    src/new_functions/lambdas.cpp)
add_executable(currying
    src/new_functions/currying.cpp)
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 6.4)
        add_executable(currying17
            src/new_functions/currying17.cpp)
    endif()
endif()
add_executable(function_composition
    src/new_functions/function_composition.cpp)
add_executable(function_lifting
    src/new_functions/function_lifting.cpp)
