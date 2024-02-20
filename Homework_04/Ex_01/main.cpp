//
// Created by Tamour on 19/02/2024.
//
#include <iostream>
#include "PathDependentOption01.h"



using namespace std;

int main() {
    double S0 = 100.0, r = 0.03, sigma = 0.2;
    BSModel Model(S0, r, sigma);

    double T = 1.0 / 12.0, K = 100.0; // Expiry is 1 month.

    int m = 30; // Daily observations for one month.

    ArithAsianCall ArithAsianCallOption(T, K, m);

    long N = 300;
    cout << "Asian Call Price = " << ArithAsianCallOption.PriceByMC(Model, N) << endl;

    // European Call option
    EuropeanCall EuroCallOption(T, K, m);
    cout << "European Call Price = " << EuroCallOption.PriceByMC(Model, N) << endl;

    // European Put option
    EuropeanPut EuroPutOption(T, K, m);
    cout << "European Put Price = " << EuroPutOption.PriceByMC(Model, N) << endl;

    return 0;
}