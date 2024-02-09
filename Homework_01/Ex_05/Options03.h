//
// Created by Tamour on 09/02/2024.
//

#ifndef QUANT_HOMEWORK_OPTIONS03_H
#define QUANT_HOMEWORK_OPTIONS03_H


#ifndef Options03_h
#define Options03_h

double PriceByCRR(double S0, double U, double D, double R, int N, double K, double(*Payoff)(double z, double K));
double CallPayoff(double z, double K);
double PutPayoff(double z, double K);
double NewtonSymb(int N, int i);
double PriceAnalytic(double S0, double U, double D, double R, int N, double K, double(*Payoff)(double z, double K));

#endif /* Options03_h */



#endif //QUANT_HOMEWORK_OPTIONS03_H
