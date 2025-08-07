cmake_minimum_required(VERSION 3.10)
project(Neural_network)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -pthread")

add_executable(
    Neural_network
    src/main.cpp
    src/Neuron.cpp
    src/Matrix.cpp
    src/Layer.cpp
    src/utils/Math.cpp
)
