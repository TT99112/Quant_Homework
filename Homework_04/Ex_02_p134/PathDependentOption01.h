//
// Created by Tamour on 19/02/2024.
//

#ifndef QUANT_HOMEWORK_PATHDEPENDENTOPTION01_H
#define QUANT_HOMEWORK_PATHDEPENDENTOPTION01_H

#include "Model01.h"

class PathDepOption {
public:
    double T;
    int m;

    double PriceByMC(BSModel Model, long N);
    virtual double Payoff(SamplePath& S) = 0;

};

class ArithAsianCall : public PathDepOption {
public:
    double K;

    ArithAsianCall(double T, double K, int m) {
        this->T = T;
        this->K = K;
        this->m = m;
    }

    double Payoff(SamplePath& S);
};

#endif //QUANT_HOMEWORK_PATHDEPENDENTOPTION03_H
