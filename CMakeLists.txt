cmake_minimum_required(VERSION 3.21)
project(SISE1)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXE_LINKER_FLAGS "-static")

include_directories(.)

add_executable(SISE1
        Bfs.cpp
        Bfs.h
        Board.cpp
        Board.h
        Dfs.cpp
        Dfs.h
        main.cpp Astr.cpp Astr.h)
