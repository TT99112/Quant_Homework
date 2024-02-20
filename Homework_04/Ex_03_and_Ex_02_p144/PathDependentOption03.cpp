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
    double H = 0.0, Hsq = 0.0;
    SamplePath S(m);
    double HepsPlus = 0.0, HepsMinus = 0.0, Hvega = 0.0, Htheta = 0.0, Hrho = 0.0;
    for (long i = 0; i < N; i++) {
        Model.GenerateSamplePath(T, m, S);
        // Standard calculations for H and Hsq
        H = (i * H + Payoff(S)) / (i + 1.0);
        Hsq = (i * Hsq + pow(Payoff(S), 2.0)) / (i + 1.0);

        // Calculations for Gamma
        Rescale(S, 1.0 + epsilon); // Scaled up
        HepsPlus = (i * HepsPlus + Payoff(S)) / (i + 1.0);
        Rescale(S, (1.0 - epsilon) / (1.0 + epsilon)); // Scaled down, then adjusted to original
        HepsMinus = (i * HepsMinus + Payoff(S)) / (i + 1.0);
        Rescale(S, 1.0 / (1.0 - epsilon)); // Reset S to original for the next iteration

        // For Vega: Increase sigma
        double originalSigma = Model.sigma;
        Model.sigma += epsilon;
        Model.GenerateSamplePath(T, m, S);
        Hvega = (i * Hvega + Payoff(S)) / (i + 1.0);
        Model.sigma = originalSigma; // Reset sigma

        // For Theta: Decrease T
        double originalT = T;
        T -= epsilon;
        if (T < 0) T = epsilon; // Ensure T is not negative
        Model.GenerateSamplePath(T, m, S);
        Htheta = (i * Htheta + Payoff(S)) / (i + 1.0);
        T = originalT; // Reset T

        // For Rho: Increase r
        double originalR = Model.r;
        Model.r += epsilon;
        Model.GenerateSamplePath(T, m, S);
        Hrho = (i * Hrho + Payoff(S)) / (i + 1.0);
        Model.r = originalR; // Reset r
    }

    double disc = exp(-Model.r * T);
    Price = disc * H;
    PricingError = disc * sqrt(Hsq - H * H) / sqrt(N - 1.0);
    delta = disc * (HepsPlus - H) / (Model.S0 * epsilon);
    gamma = disc * (HepsPlus - 2*H + HepsMinus) / (Model.S0 * Model.S0 * epsilon * epsilon);
    vega = disc * (Hvega - H) / epsilon; // Sensitivity to sigma
    theta = disc * (H - Htheta) / epsilon; // Sensitivity to T
    rho = disc * (Hrho - H) / epsilon; // Sensitivity to r

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
