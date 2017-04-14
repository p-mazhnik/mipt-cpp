cmake_minimum_required(VERSION 3.6)
project(mipt_cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        #"Matrix 28.02/main.cpp" "Matrix 28.02/Matrix.cpp" "Matrix 28.02/Matrix.h"
        Function/Function.cpp
        )

add_executable(mipt_cpp ${SOURCE_FILES})