//
// Created by Tamour on 20/02/2024.
//
#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate U and D factors
void calculateUDFactors(double sigma, double& U, double& D) {
    double deltaT = 1.0; // Assuming 1 time period for simplicity
    U = exp(sigma * sqrt(deltaT));
    D = exp(-sigma * sqrt(deltaT));
}

// Function to calculate risk-neutral probability
double calculateRiskNeutralProb(double U, double D, double R, double deltaT) {
    return (exp(R * deltaT) - D) / (U - D);
}

// Function to calculate call option price using a single-period binomial model
double calculateOptionPrice(double S0, double K, double R, double U, double D, double q) {
    double deltaT = 1.0; // Assuming 1 time period for simplicity
    double Cu = max(0.0, S0 * U - K); // Payoff if stock goes up
    double Cd = max(0.0, S0 * D - K); // Payoff if stock goes down
    double discountFactor = exp(-R * deltaT);

    // Option price as the expected value of future payoffs discounted back to present
    return discountFactor * (q * Cu + (1 - q) * Cd);
}

int main() {
    double sigma = 0.20; // Volatility
    double S0 = 100; // Current stock price
    double K = 100; // Strike price
    double R = 0.05; // Risk-free rate

    double U, D;
    calculateUDFactors(sigma, U, D);

    double deltaT = 1.0; // Assuming 1 time period for simplicity
    double q = calculateRiskNeutralProb(U, D, R, deltaT);

    double optionPrice = calculateOptionPrice(S0, K, R, U, D, q);

    cout << "Option Price: " << optionPrice << endl;

    // Implement further calculations for Delta and Vega as needed

    return 0;
}