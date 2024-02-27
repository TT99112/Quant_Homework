//
// Created by Tamour on 25/02/2024.
//

#ifndef QUANT_HOMEWORK_PATHDEPOPTION05_H
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
    DifferenceOfOptions(double T_, int m_, PathDepOption* Ptr1_, PathDepOption* Ptr2_)
    { T = T_; m = m_; Ptr1 = Ptr1_; Ptr2 = Ptr2_; }
    double Payoff(SamplePath& S) { return Ptr1->Payoff(S) - Ptr2->Payoff(S); }
};

class ArithmeticAsianCall : public PathDepOption {
public:
    double K;
    ArithmeticAsianCall(double T_, double K_, int m_) { T = T_; K = K_; m = m_; }
    double Payoff(SamplePath& S);
};


#endif //QUANT_HOMEWORK_PATHDEPOPTION05_H
