cmake_minimum_required(VERSION 3.3)
project(cpp-examples)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES examples/dma/dma.cpp examples/dma/usedma.cpp)

add_executable(demo ${SOURCE_FILES})

