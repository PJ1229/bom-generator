cmake_minimum_required(VERSION 3.18)
project(bom_generator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(main.exe main.cpp)