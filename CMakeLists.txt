cmake_minimum_required(VERSION 3.6)
project(mipt_cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        #"Matrix 28.02/main.cpp" "Matrix 28.02/Matrix.cpp" "Matrix 28.02/Matrix.h"
        #Function/Function.cpp
        #"BigInt 07.03/main.cpp" "BigInt 07.03/BigInt.cpp" "BigInt 07.03/BigInt.h"
        #Geometry_26.03/Vector/Vector.cpp Geometry_26.03/Vector/Vector.h Geometry_26.03/Vector/main.cpp #Geometry_26.03/Vector/rubbish/A.cpp
        #18.04/Complex.cpp 18.04/test15.cpp #Seminar/25.04/main.cpp Seminar/25.04/Radio.cpp
        #Contest_2sem_2/Q_Radio/Q_Radio.cpp
        Contest_2sem_2/S/S.cpp
        #Contest_2sem_2/sdacha/sdacha.cpp
        )

add_executable(mipt_cpp ${SOURCE_FILES})