//
// Created by Tamour on 19/02/2024.
//

#include "Model01.h"
#include <cmath>

const double pi = 4.0 * atan(1.0);

double Gauss() {
    double U1 = (rand() + 1.0) / (RAND_MAX + 1.0);
    double U2 = (rand() + 1.0) / (RAND_MAX + 1.0);

    return sqrt(-2.0 * log(U1)) * cos(2.0 * pi * U2);
}

void BSModel::GenerateSamplePath(double T, int m, SamplePath& S)
{
    double St = S0;
    double dt = T / m;
    for (int k = 0; k < m; k++) {
        S[k] = St * exp((r - sigma * sigma * 0.5) * dt
                        + sigma * sqrt(T / m) * Gauss());
        St = S[k];
    }
}

void VasicekModel::GenerateSamplePath(double T, int m, vector<double>& r) {
    r.resize(m + 1);
    r[0] = r0;
    double dt = T / m;
    for (int k = 0; k < m; k++) {
        r[k + 1] = r[k] + alpha * (beta - r[k]) * dt + sigma * sqrt(dt) * Gauss();
    }
}

void HullWhiteModel::GenerateSamplePath(double T, int m, vector<double>& r)
{
    r.resize(m + 1);
    r[0] = r0;
    double dt = T / m;
    for (int k = 0; k < m; k++) {
        r[k + 1] = r[k] + alpha * (0.0 - r[k]) * dt + sigma * sqrt(dt) * Gauss();
    }
}