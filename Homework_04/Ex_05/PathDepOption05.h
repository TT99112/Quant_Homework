//
// Created by Tamour on 25/02/2024.
//

#ifndef QUANT_HOMEWORK_PATHDEPOPTION05_H
#define QUANT_HOMEWORK_PATHDEPOPTION05_H

#include "BSModel02.h"

class PathDepOption {
public:
    double T;
    int m;
    double PriceByMC(BSModel Model, long N);
    virtual double Payoff(SamplePath& S) = 0;
};


class ArthmAsianCall : public PathDepOption {
public:
    double K;
    ArthmAsianCall(double T_, double K_, int m_) { T = T_; K = K_; m = m_; }
    double Payoff(SamplePath& S);
};


class BasketCallOption : public PathDepOption {
public:
    Vector K; // Vector of strike prices
    BasketCallOption(double T_, const Vector& K_, int m_) { T = T_; K = K_; m = m_; } // Constructor

    // Function to calculate the payoff of the basket call option
    double Payoff(SamplePath& S) override;
};


#endif //QUANT_HOMEWORK_PATHDEPOPTION05_H
