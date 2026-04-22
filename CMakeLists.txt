cmake_minimum_required(VERSION 3.10)
project(oj_code LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-O2 -pipe -Wall -Wextra -Wfatal-errors)
endif()

add_executable(code main.cpp)

