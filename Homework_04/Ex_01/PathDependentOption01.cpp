//
// Created by Tamour on 19/02/2024.
//

#include "PathDependentOption01.h"
#include <cmath>

double PathDepOption::PriceByMC(BSModel Model, long N) {
    double H = 0.0;
    SamplePath S(m); // you need to supply the size of the vector of doubles here!

    for (long i = 0; i < N; i++)
    {
        Model.GenerateSamplePath(T, m, S);
        H += Payoff(S);
    }

    return exp(-Model.r * T) * H / N;
}

double ArithAsianCall::Payoff(SamplePath& S) {
    double Ave = 0.0;
    for (int k = 0; k < m; k++)
        Ave = (k * Ave + S[k]) / (k + 1.0);
    if (Ave < K)
        return 0.0;
    return Ave - K;
}

// Implement the Payoff function for EuropeanCall
double EuropeanCall::Payoff(SamplePath& S) {
    double ST = S.back(); // Get the last stock price from the sample path
    return std::max(0.0, ST - K); // Payoff for a call option
}

// Implement the Payoff function for EuropeanPut
double EuropeanPut::Payoff(SamplePath& S) {
    double ST = S.back(); // Get the last stock price from the sample path
    return std::max(0.0, K - ST); // Payoff for a put option
}