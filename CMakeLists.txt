cmake_minimum_required(VERSION 3.21)
project(delta)

set(CMAKE_CXX_STANDARD 20)

add_executable(delta main.cpp src/vecChar8toInt64.cpp src/vecChar8toInt64.h src/decompress.h src/decompress.cpp src/dic.h src/dic.cpp src/parent.h src/parent.cpp src/child.h src/child.cpp src/int64toString.h src/int64toString.cpp src/index.h src/index.cpp)
