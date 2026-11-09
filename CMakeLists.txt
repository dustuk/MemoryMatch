cmake_minimum_required(VERSION 4.3)
project(MemoryMatch)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib REQUIRED)

add_executable(MemoryMatch src/main.cpp
        src/Game.cpp
        src/Game.h
        src/CardBoard.cpp
        src/CardBoard.h
        src/MainMenu.cpp
        src/MainMenu.h)

target_link_libraries(MemoryMatch PRIVATE raylib)