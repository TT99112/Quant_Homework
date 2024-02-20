//
// Created by Tamour on 19/02/2024.
//
#include <iostream>
#include "PathDependentOption03.h"



using namespace std;

int main()
{
    double S0 = 100.0, r = 0.03, sigma = 0.2;
    BSModel Model(S0, r, sigma);

    double T = 1.0 / 12.0, K = 100.0; // Expiry is 1 month.

    int m = 30; // Daily observations for one month.

    ArithAsianCall ArithAsianCallOption(T, K, m);

    long N = 30000;
    cout << "Asian Call Price = " << ArithAsianCallOption.PriceByMC(Model, N, 0.001) << endl;

    return 0;
}