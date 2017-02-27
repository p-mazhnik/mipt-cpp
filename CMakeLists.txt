cmake_minimum_required(VERSION 3.6)
project(mipt_cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        "String 21.02/main.cpp" "String 21.02/String.cpp" "String 21.02/String.h")

add_executable(mipt_cpp ${SOURCE_FILES})