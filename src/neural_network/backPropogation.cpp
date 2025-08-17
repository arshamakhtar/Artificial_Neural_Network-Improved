#include "../../include/NeuralNetwork.hpp"
#include "../../include/utils/Math.hpp"

void NeuralNetwork::backPropgation(){
    vector<Matrix*> newWeights;
    //Part1: OUTPUT TO LAST HIDDEN LAYER
    int indexOutputLayer = this->topology.size() - 1;
    Matrix* deltaWeights = new Matrix(this-> weightMatrices.at(indexOutputLayer - 1)->getNumRows(), this-> weightMatrices.at(indexOutputLayer - 1)->getNumCols(),false);

    Matrix* gradients = new Matrix( 1, this-> topology.at(indexOutputLayer), false);
    
    Matrix* derivedValues = this->Layers.at(indexOutputLayer)->matrixifyDerivedVals();

    for(int i = 0 ; i < this-> topology.at(indexOutputLayer); ++i){
        double e = this-> derivedErrors.at(i);
        double y = derivedValues->getValue(0, i);
        gradients->setValue(0, i, e * y);
    }
    delete derivedValues;

    //Gt * z
    Matrix * gradientTransposed = gradients-> transpose();
    Matrix * zValues            = this-> Layers.at(indexOutputLayer - 1)->matrixifyActivatedVals();

    utils::Math::multiplyMatrix(gradientTransposed , zValues, deltaWeights);

    Matrix *tempNewWeights = new Matrix(
                                this->topology.at(indexOutputLayer -1),
                                this->topology.at(indexOutputLayer),
                                false
                            );
    for(int r = 0; r < this-> topology.at(indexOutputLayer-1); ++r){
        for(int c = 0; c < this->topology.at(indexOutputLayer); ++c){
            double originalValue      = this->weightMatrices.at(indexOutputLayer -1)->getValue(r ,c);
            double deltaValue         = deltaWeights->getValue(r , c);

            originalValue             = this->momentum * originalValue;
            deltaValue                = this->learningRate  * deltaValue;

            tempNewWeights -> setValue(r, c, (originalValue - deltaValue));
        }
    }

    newWeights.push_back(new Matrix(*tempNewWeights));
    delete tempNewWeights;

    delete deltaWeights;
    delete gradients;
    
    //Part2: LAST HIDDEN LAYER TO INPUT LAYER
}