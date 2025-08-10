#ifndef _NEURAL_NETWORK_HPP_
#define _NEURAL_NETWORK_HPP_

#define COST_MSE 1

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <time.h>
#include "Matrix.hpp"
#include "Layer.hpp"

using namespace std;

class NeuralNetwork{
    public:
        NeuralNetwork( vector<int> topology,
                        double bias = 1, 
                        double learningRate=0.05,
                        double momentum =1
                        );

        NeuralNetwork( vector<int> topology,
                        int hiddenActivationType,
                        int outputActivationType,
                        int costFunctionType,
                        double bias = 1, 
                        double learningRate=0.05,
                        double momentum =1
                        );
                        
        void setCurrentInput(vector<double> input);
        void setCurrentTarget(vector<double> target){   this-> target = target ; };
        
        void feedForward();
        void backPropgation();
        void setErrors();
        

        int topologySize;
        int hiddenActivationType    =  RELU;
        int outputActivationType    =  SIGM;
        int costFunctionType        =  COST_MSE;
        
        vector<int> topology;
        vector<Layer *> Layers;
        vector<Matrix *> weightMatrices;
        vector<Matrix *> gradientMatrices;

        vector<double> input;
        vector<double> target;
        vector<double> errors;
        vector<double> derivedErrors;

        double error                =  0;
        double bias                 =  1;
        double momentum;
        double learningRate;
        
    private:
        void setErrorMSE();
};

#endif