//
// Created by Tamour on 25/02/2024.
//

#ifndef QUANT_HOMEWORK_PATHDEPOPTION04_H
#define QUANT_HOMEWORK_PATHDEPOPTION04_H

#include "BSModel01.h"

class PathDepOption {
public:
    double T, Price, PricingError;
    int m;
    virtual double Payoff(SamplePath& S) = 0;
    double PriceByMC(BSModel Model, long N);
    double PriceByVarRedMC(BSModel Model, long N, PathDepOption& CVOption);
    virtual double PriceByBSFormula(BSModel Model) { return 0.0; }
};

class DifferenceOfOptions : public PathDepOption {
public:
    PathDepOption* Ptr1;
    PathDepOption* Ptr2;
    DifferenceOfOptions(double T, int m, PathDepOption* Ptr1, PathDepOption* Ptr2) {
        this->T = T; this->m = m; this->Ptr1 = Ptr1; this->Ptr2 = Ptr2;
    }
    double Payoff(SamplePath& S) {
        return Ptr1->Payoff(S) - Ptr2->Payoff(S);
    }
};

class ArithmAsianCall : public PathDepOption {
public:
    double K;
    ArithmAsianCall(double T, double K, int m) { this->T = T; this->K = K; this->m = m; }
    double Payoff(SamplePath& S);
};


#endif //QUANT_HOMEWORK_PATHDEPOPTION05_H
