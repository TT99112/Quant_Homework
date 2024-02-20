//
// Created by Tamour on 19/02/2024.
//
#include <iostream>
#include "PathDependentOption01.h"



using namespace std;

int main() {
    // Black-Scholes parameters
    double S0 = 100.0, r = 0.03, sigma = 0.2;
    // Vasicek parameters
    double r0_vasicek = 0.05, alpha_vasicek = 0.1, beta_vasicek = 0.05, sigma_vasicek = 0.02;
    // Hull-White parameters
    double r0_hw = 0.05, alpha_hw = 0.1, sigma_hw = 0.02;

    double T = 1.0; // Time horizon
    int m = 100;    // Number of time steps

    // Generate sample paths for Black-Scholes, Vasicek, and Hull-White models
    vector<double> samplePathBS(m);
    vector<double> samplePathVasicek(m + 1); // Need m + 1 points for Vasicek
    vector<double> samplePathHW(m + 1);      // Need m + 1 points for Hull-White

    // Initialize models
    BSModel bsModel(S0, r, sigma);
    VasicekModel vasicekModel(r0_vasicek, alpha_vasicek, beta_vasicek, sigma_vasicek);
    HullWhiteModel hwModel(r0_hw, alpha_hw, sigma_hw);

    // Generate sample paths
    bsModel.GenerateSamplePath(T, m, samplePathBS);
    vasicekModel.GenerateSamplePath(T, m, samplePathVasicek);
    hwModel.GenerateSamplePath(T, m, samplePathHW);

    // Print the generated sample paths
    cout << "Black-Scholes sample path:" << endl;
    for (int i = 0; i < m; ++i) {
        cout << "S[" << i << "] = " << samplePathBS[i] << endl;
    }

    cout << "\nVasicek sample path:" << endl;
    for (int i = 0; i <= m; ++i) {
        cout << "r[" << i << "] = " << samplePathVasicek[i] << endl;
    }

    cout << "\nHull-White sample path:" << endl;
    for (int i = 0; i <= m; ++i) {
        cout << "r[" << i << "] = " << samplePathHW[i] << endl;
    }

    return 0;
}