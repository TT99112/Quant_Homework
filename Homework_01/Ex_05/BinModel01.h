//
// Created by Tamour on 09/02/2024.
//

#ifndef QUANT_HOMEWORK_BINMODEL01_H
#define QUANT_HOMEWORK_BINMODEL01_H


double riskNeutralProb(double U, double D, double R);
double S(double S0, double U, double D, int n, int i);
int getInputData(double* S0, double* U, double* D, double* R);

#endif //QUANT_HOMEWORK_BINMODEL01_H
