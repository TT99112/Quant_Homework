//
// Created by Tamour on 25/02/2024.
//

#ifndef QUANT_HOMEWORK_GMTRASIANCALL_H
#define QUANT_HOMEWORK_GMTRASIANCALL_H


#include "PathDepOption04.h"

class GmtrAsianCall : public PathDepOption {
public:
    double K;
    GmtrAsianCall(double T_, double K_, int m_) { T = T_; K = K_; m = m_; }
    double Payoff(SamplePath& S);
    double PriceByBSFormula(BSModel Model);
};


#endif //QUANT_HOMEWORK_GMTRASIANCALL_H
