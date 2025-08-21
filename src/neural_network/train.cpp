#include "../../include/NeuralNetwork.hpp"

void NeuralNetwork::train(
  vector<double> input, 
  vector<double> target, 
  double bias, 
  double learningRate, 
  double momentum
) {
  this->learningRate  = learningRate;
  this->momentum      = momentum;
  this->bias          = bias;

  this->setCurrentInput(input);
  this->setCurrentTarget(target);
  cout<<"This works"<<endl;
  this->feedForward();
  cout<<"Hello"<<endl;
  this->setErrors();
  this->backPropagation();
}
