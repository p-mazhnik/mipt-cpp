cmake_minimum_required(VERSION 3.6)
project(mipt_cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        #"Matrix 28.02/main.cpp" "Matrix 28.02/Matrix.cpp" "Matrix 28.02/Matrix.h"
        #Function/Function.cpp
        #"BigInt 07.03/main.cpp" "BigInt 07.03/BigInt.cpp" "BigInt 07.03/BigInt.h"
        #Geometry_26.03/Vector/Vector.cpp Geometry_26.03/Vector/Vector.h Geometry_26.03/Vector/main.cpp
        #Geometry_26.03/Vector/rubbish/A.cpp
        #18.04/Complex.cpp 18.04/test15.cpp
        #Seminar/20.09.17_FenwikTree/main_3013.cpp
        #Seminar/20.09.17_FenwikTree/main_111778.cpp
        #Seminar/27.09.17_DecardTree/main.cpp
        Seminar/11.10.17_Graph/DFS_D_165.cpp Seminar/11.10.17_Graph/8_BFS_1994.cpp)

add_executable(mipt_cpp ${SOURCE_FILES})