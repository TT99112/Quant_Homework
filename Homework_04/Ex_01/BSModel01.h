//
// Created by Tamour on 19/02/2024.
//

#ifndef QUANT_HOMEWORK_MODEL01_H
#define QUANT_HOMEWORK_BSMODEL01_H

#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef vector<double> SamplePath;


class BSModel
        {
public:
    double S0;
    double r;
    double sigma;
    BSModel(double S0, double r, double sigma) : S0(S0), r(r), sigma(sigma) {
        srand(time(NULL));
    }

    void GenerateSamplePath(double T, int m, SamplePath& S);

};

#endif //QUANT_HOMEWORK_MODEL01_H
