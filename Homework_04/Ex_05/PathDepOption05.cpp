//
// Created by Tamour on 25/02/2024.
//

#include "PathDepOption05.h"
#include <cmath>

double PathDepOption::PriceByMC(BSModel Model, long N)
{
    double H = 0.0;
    SamplePath S(m);
    for (long i = 0; i < N; i++)
    {
        Model.GenerateSamplePath(T, m, S);
        H = (i * H + Payoff(S)) / (i + 1.0);
    }
    return exp(-Model.r * T) * H;
}



double ArthmAsianCall::Payoff(SamplePath& S)
{
    double Ave = 0.0;
    int d = S[0].size();
    Vector one(d);
    for (int i = 0; i < d; i++)
        one[i] = 1.0;
    for (int k = 0; k < m; k++)
    {
        Ave = (k * Ave + (one ^ S[k])) / (k + 1.0);
    }
    if (Ave < K)
        return 0.0;
    return Ave - K;
}

double BasketCallOption::Payoff(SamplePath& S) {
    int d = S[0].size(); // Dimension
    double sum_S = 0.0;
    for (int j = 0; j < d; j++) {
        sum_S += S[m - 1][j]; // Sum of all asset prices at maturity
    }
    double avg_price = sum_S / d; // Average price of the basket
    double payoff = 0.0; // Initialize payoff
    for (int j = 0; j < d; j++) {
        payoff += max(S[m - 1][j] - K[j], 0.0); // Payoff for each asset
    }
    return payoff;
}