cmake_minimum_required(VERSION 3.20)
project(eda_pf)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

add_executable(eda_pf src/main.cpp src/parser.cpp)