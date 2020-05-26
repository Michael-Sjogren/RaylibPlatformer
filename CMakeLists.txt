cmake_minimum_required(VERSION 3.16)
project(raylibgame)

set(CMAKE_CXX_STANDARD 14)

add_executable(raylibgame main.cpp)
find_package(raylib REQUIRED)
target_link_libraries(raylibgame raylib)