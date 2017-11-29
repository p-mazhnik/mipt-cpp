cmake_minimum_required(VERSION 3.6)
project(mipt_cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        #Contest_3sem_1/J/J_v2.cpp
        #Contest_3sem_1/A_SparseTable/A_v2.cpp
        #Contest_3sem_1/C_SegmentTree/C.cpp
        #HomeWork/Dijkstra_inf_6.cpp
        #HomeWork/Floyd_inf_98.cpp
        #Contest_3sem_2/F_BellmanFord/Bellman_Ford_inf_180.cpp
        #Contest_3sem_2/G/G.cpp
        #Contest_3sem_2/I_Floyd/I.cpp
        Contest_3sem_2/G/G_v2.cpp
        #Contest_3sem_2/C_disjoint-set-union/C_DSU.cpp
        )
add_executable(mipt_cpp ${SOURCE_FILES})