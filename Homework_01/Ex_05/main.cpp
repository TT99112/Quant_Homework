//
// Created by Tamour on 09/02/2024.
//
#include "BinModel01.h"
#include "Options03.h"
#include <iostream>
#include <cmath>
using namespace std;


int main() {
    double S0, U, D, R, K;
    int N;

    // Get input data
    getInputData(&S0, &U, &D, &R);

    // Get input for N and K
    cout << "Enter N: ";
    cin >> N;
    cout << "Enter K: ";
    cin >> K;

    // Calculate option price using binomial tree method
    double binomialPrice = PriceByCRR(S0, U, D, R, N, K, CallPayoff);

    // Calculate option price using the provided CRR formula
    double analyticPrice = PriceAnalytic(S0, U, D, R, N, K, CallPayoff);

    // Output the results
    std::cout << "Binomial Tree Price: " << binomialPrice << std::endl;
    std::cout << "Analytic Price: " << analyticPrice << std::endl;

    return 0;
}
