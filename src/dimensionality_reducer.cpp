#include <iostream>
#include <fstream>
#include <vector>
#include "../include/json.hpp"
#include "../include/NeuralNetwork.hpp"
#include "../include/utils/Misc.hpp"

using namespace std;
using json = nlohmann::json;

// Add the same buildConfig function from train.cpp
ANNConfig buildConfig(json configObject) {
    ANNConfig config;

    double learningRate = configObject["learningRate"];
    double momentum = configObject["momentum"];
    double bias = configObject["bias"];
    int epoch = configObject["epoch"];
    string trainingFile = configObject["trainingFile"];
    string labelsFile = configObject["labelsFile"];
    string weightsFile = configObject["weightsFile"];
    vector<int> topology = configObject["topology"];

    ANN_ACTIVATION hActivation = configObject["hActivation"];
    ANN_ACTIVATION oActivation = configObject["oActivation"];

    config.topology = topology;
    config.bias = bias;
    config.learningRate = learningRate;
    config.momentum = momentum;
    config.epoch = epoch;
    config.hActivation = hActivation;
    config.oActivation = oActivation;
    config.trainingFile = trainingFile;
    config.labelsFile = labelsFile;
    config.weightsFile = weightsFile;

    return config;
}

int main(int argc, char **argv) {
    if(argc != 3) {
        cout << "Usage: dimensionality_reducer [configFile] [dataFile]" << endl;
        exit(-1);
    }
    
    // Load configuration
    ifstream configFile(argv[1]);
    string str((std::istreambuf_iterator<char>(configFile)),
              std::istreambuf_iterator<char>());
    
    // Parse JSON and build ANNConfig struct
    json configJson = json::parse(str);
    ANNConfig config = buildConfig(configJson);
    
    // Create neural network with proper config
    NeuralNetwork *n = new NeuralNetwork(config);
    
    // Load trained weights
    n->loadWeights(config.weightsFile);
    
    // Load data to reduce
    vector<vector<double>> inputData = utils::Misc::fetchData(argv[2]);
    
    cout << "Original dimensions: " << inputData.size() << endl;
    cout << "Reduced dimensions: " << config.topology[config.topology.size()/2] << endl;
    
    // Process each data point
    for(int i = 0; i < inputData.size(); i++) {
        n->setCurrentInput(inputData.at(i));
        n->encodeOnly(); // Only forward through encoder
        
        vector<double> encoded = n->getEncodedRepresentation();
        
        // Output reduced representation
        for(int j = 0; j < encoded.size(); j++) {
            cout << encoded[j];
            if(j < encoded.size()-1) cout << ",";
        }
        cout << endl;
    }
    
    delete n;
    return 0;
}
