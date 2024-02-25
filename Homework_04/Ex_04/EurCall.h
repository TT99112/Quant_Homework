//
// Created by Tamour on 25/02/2024.
//

#ifndef QUANT_HOMEWORK_EURCALL_H
#define QUANT_HOMEWORK_EURCALL_H


#include <cmath>

class EurCall {
public:
    double T, K;
    EurCall(double T_, double K_) { T = T; K = K; }
    double dplus(double S0, double sigma, double r);
    double dminus(double S0, double sigma, double r);
    double PriceByBSFormula(double S0, double sigma, double r);
    double VegaByBSFormula(double S0, double sigma, double r);
};



#endif //QUANT_HOMEWORK_EURCALL_H
