cmake_minimum_required(VERSION 3.10)
project(Neural_network)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -pthread")

# Training executable
add_executable(
    train
    src/train.cpp
    src/Neuron.cpp
    src/Matrix.cpp
    src/Layer.cpp
    src/utils/Math.cpp
    src/utils/Misc.cpp
    src/neural_network/NeuralNetwork.cpp
    src/neural_network/setErrors.cpp
    src/neural_network/loadWeights.cpp
    src/neural_network/feedForward.cpp
    src/neural_network/backPropagation.cpp
    src/neural_network/train.cpp
    src/neural_network/constructor.cpp
)

# Dimensionality reducer executable
add_executable(
    dimensionality_reducer
    src/dimensionality_reducer.cpp
    src/Neuron.cpp
    src/Matrix.cpp
    src/Layer.cpp
    src/utils/Math.cpp
    src/utils/Misc.cpp
    src/neural_network/NeuralNetwork.cpp
    src/neural_network/setErrors.cpp
    src/neural_network/feedForward.cpp
    src/neural_network/forwardPass.cpp
    src/neural_network/loadWeights.cpp
    src/neural_network/backPropagation.cpp
    src/neural_network/train.cpp
    src/neural_network/constructor.cpp
)
# Autoencoder classifier executable
add_executable(
    autoencoder_classify
    src/autoencoder_classify.cpp
    src/Neuron.cpp
    src/Matrix.cpp
    src/Layer.cpp
    src/utils/Math.cpp
    src/utils/Misc.cpp
    src/neural_network/NeuralNetwork.cpp
    src/neural_network/setErrors.cpp
    src/neural_network/feedForward.cpp
    src/neural_network/constructor.cpp
    src/neural_network/loadWeights.cpp
)