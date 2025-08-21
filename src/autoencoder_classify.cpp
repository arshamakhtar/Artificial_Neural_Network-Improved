#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include "../include/json.hpp"
#include "../include/NeuralNetwork.hpp"
#include "../include/utils/Misc.hpp"

using namespace std;
using json = nlohmann::json;

void printSyntax() {
    cout << "Syntax:" << endl;
    cout << "autoencoder_classify [configFile]" << endl;
}

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
    if(argc != 2) {
        printSyntax();
        exit(-1);
    }

    ifstream configFile(argv[1]);
    string str((std::istreambuf_iterator<char>(configFile)),
              std::istreambuf_iterator<char>());

    // Parse JSON and build ANNConfig
    json configJson = json::parse(str);
    ANNConfig config = buildConfig(configJson);

    cout << "Topology: " << endl;
    for(int i = 0; i < config.topology.size(); i++) {
        cout << config.topology.at(i) << "\t";
    }
    cout << endl;

    // Create neural network with proper ANNConfig
    NeuralNetwork *n = new NeuralNetwork(config);
    n->loadWeights(config.weightsFile);

    vector<vector<double>> testData = utils::Misc::fetchData(config.trainingFile);

    for(int i = 0; i < testData.size(); i++) {
        n->setCurrentInput(testData.at(i));
        n->setCurrentTarget(testData.at(i));
        n->feedForward();
        n->setErrors();

        double error = n->error;
        cout << error << endl;
    }

    delete n;
    return 0;
}
