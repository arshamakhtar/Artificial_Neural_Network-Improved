#include "../../include/NeuralNetwork.hpp"

void NeuralNetwork::setErrors(){
    if(this->target.size() == 0) {
        cerr<< " No target for this Neural Network"<< endl;
        assert(false);
    }

    if(this->target.size() != this->Layers.at(this-> Layers.size() - 1)-> getNeuron().size()){
        cerr<< "Target size(" <<this->target.size()<< ") is not the smase as the output layer size; "<< this-> Layers.at(this->Layers.size() -1)-> getNeuron().size()<< endl;
        for(int i = 0; i< this-> target.size(); i++){
            cout<<this->target.at(i)<< endl;
        }
        assert(false);
    }
    
    switch(costFunctionType) {
        case(COST_MSE): this->setErrorMSE(); break;
        default: this->setErrorMSE(); break;
    }
}

void NeuralNetwork::setErrorMSE() {
    int outputLayerIndex = this-> Layers.size() - 1;
    vector<Neuron *> outputNeurons = this-> Layers.at(outputLayerIndex)->getNeuron();

    this-> error = 0.00;

    for(int i = 0 ; i < target.size() ; i++){
        double t = target.at(i);
        double y = outputNeurons.at(i)-> getActivatedVal();
        
        errors.at(i)        = pow(abs(t - y), 2);
        derivedErrors.at(i) = y - t;

        this-> error += errors.at(i);
    }
}