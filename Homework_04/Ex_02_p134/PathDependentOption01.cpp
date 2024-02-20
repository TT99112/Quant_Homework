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

double EuroCall::Payoff(SamplePath& S) {
    return max(0.0, S.back() - K); // Payoff at expiry
}

double EuroPut::Payoff(SamplePath& S) {
    return max(0.0, K - S.back()); // Payoff at expiry
}