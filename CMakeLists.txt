cmake_minimum_required(VERSION 3.12)

project(sample-project CXX)

set(CMAKE_CXX_STANDART 20)
set(CMAKE_CXX_STANDART_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

add_compile_options(-std=c++${CMAKE_CXX_STANDART})

add_compile_definitions(_NDEBUG)
add_compile_options(-Wall -Wextra)

#add_subdirectory(bad-wordle)
#add_subdirectory(sample-project)
add_subdirectory(syscalls)
add_subdirectory(environment)