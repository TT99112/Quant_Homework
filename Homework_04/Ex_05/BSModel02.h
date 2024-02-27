//
// Created by Tamour on 19/02/2024.
//

#ifndef QUANT_HOMEWORK_BSMODEL02_H
#define QUANT_HOMEWORK_BSMODEL02_H

#include "Matrix.h"

using namespace std;

typedef vector<Vector> SamplePath;

class BSModel
        {
public:
    Vector S0, sigma;
    Matrix C;
    double r;
    BSModel(Vector S0, double r, Matrix C);
    void GenerateSamplePath(double T, int m, SamplePath& S);

};

#endif //QUANT_HOMEWORK_MODEL01_H
