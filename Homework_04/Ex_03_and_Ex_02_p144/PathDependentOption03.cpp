//
// Created by Tamour on 19/02/2024.
//

#include "PathDependentOption03.h"
#include <algorithm>
#include <cmath>

void Rescale(SamplePath& S, double x) {
    int m = S.size();
    for (int j = 0; j < m; j++)
        S[j] = x * S[j];
}

double PathDepOption::PriceByMC(BSModel Model, long N, double epsilon) {
    double H = 0.0, Hsq = 0.0, HepsPlus = 0.0, HepsMinus = 0.0;
    SamplePath S(m), Soriginal(m);
    for (long i = 0; i < N; i++) {
        Model.GenerateSamplePath(T, m, S);
        Soriginal = S; // Store original S to use for rescaling back

        // Payoff for original S
        H = (i * H + Payoff(S)) / (i + 1.0);
        Hsq = (i * Hsq + pow(Payoff(S), 2.0)) / (i + 1.0);

        // Payoff for S scaled up by epsilon
        Rescale(S, 1.0 + epsilon);
        HepsPlus = (i * HepsPlus + Payoff(S)) / (i + 1.0);

        // Reset S to original and then scale down by epsilon for payoff
        S = Soriginal;
        Rescale(S, 1.0 - epsilon);
        HepsMinus = (i * HepsMinus + Payoff(S)) / (i + 1.0);

        // Reset S to original for next iteration
        S = Soriginal;
    }

    double disc = exp(-Model.r * T);
    Price = disc * H;
    PricingError = disc * sqrt(Hsq - H * H) / sqrt(N - 1.0);
    delta = disc * (HepsPlus - H) / (Model.S0 * epsilon);
    gamma = disc * (HepsPlus - 2*H + HepsMinus) / (Model.S0 * Model.S0 * epsilon * epsilon);

    // Additions for Vega, Theta, Rho will follow a similar pattern, requiring modifications to BSModel and PathDepOption classes

    return Price;
}

double ArithAsianCall::Payoff(SamplePath& S) {
    double Ave = 0.0;
    for (int k = 0; k < m; k++)
        Ave = (k * Ave + S[k]) / (k + 1.0);
    if (Ave < K)
        return 0.0;
    return Ave - K;
}
