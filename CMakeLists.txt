cmake_minimum_required(VERSION 3.6)
project(mipt_cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        #Contest_3sem_2/F_BellmanFord/Bellman_Ford_inf_180.cpp
        #Contest_3sem_2/G/G.cpp
        #Contest_3sem_2/I_Floyd/I.cpp
        #Contest_3sem_2/G/G_v2.cpp
        #Contest_3sem_2/C_disjoint-set-union/C_DSU.cpp
        #Contest_3sem_2/E/E.cpp
        #Contest_3sem_2/J/J.cpp
        Contest_3sem_2/K/K.cpp
        #Contest_3sem_2/L_Dijkstra/L_Dijkstra.cpp
        #Contest_3sem_2/M/M.cpp
        )
add_executable(mipt_cpp ${SOURCE_FILES})