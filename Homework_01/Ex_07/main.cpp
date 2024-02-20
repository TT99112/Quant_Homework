//
// Created by Tamour on 20/02/2024.
//

#include <iostream>
#include <cmath>

int main() {
    // Given parameters
    double S = 100; // Current stock price
    double r = 0.06; // Risk-free rate
    double T = 1; // Time to maturity
    double sigma = 0.2; // Volatility (Black-Scholes model)
    double deltaT = T / 3; // Time step

    // Calculate U, D, and q based on the Black-Scholes assumptions
    double U = exp(sigma * sqrt(deltaT));
    double D = exp(-sigma * sqrt(deltaT));
    double q = (exp(r * deltaT) - D) / (U - D);

    std::cout << "U: " << U << std::endl;
    std::cout << "D: " << D << std::endl;
    std::cout << "Risk-neutral probability q: " << q << std::endl;

    return 0;
}