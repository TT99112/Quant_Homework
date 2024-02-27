//
// Created by Tamour on 25/02/2024.
//

#include <iostream>
#include "PathDepOption04.h"
#include "GmtrAsianCall.h"

#include "BarrierCallOption.h"
using namespace std;


int main() {
    double S0 = 100.0, r = 0.03, sigma = 0.2;
    BSModel Model(S0, r, sigma);
    double T = 1.0 / 12.0, K = 100.0, L = 105.0; // Added L for the barrier level
    int m = 30;

    // Existing options
    ArithmAsianCall Option(T, K, m);
    GmtrAsianCall CVOption(T, K, m);

    // Barrier Call Option instance
    BarrierCallOption BarrierOption(T, K, L, m); // Initialize with barrier level L

    long N = 30000;

    // Pricing the Barrier Call Option
    cout << "Pricing Barrier Call Option..." << endl;
    BarrierOption.PriceByVarRedMC(Model, N, CVOption);
    cout << "Barrier Call Option price = " << BarrierOption.Price << endl
         << "Error = " << BarrierOption.PricingError << endl;

    // Existing pricing code for arithmetic call
    Option.PriceByVarRedMC(Model, N, CVOption);
    cout << "Arithmetic call price = " << Option.Price << endl
         << "Error = " << Option.PricingError << endl;

    Option.PriceByMC(Model, N);
    cout << "Price by direct MC = " << Option.Price << endl
         << "MC Error = " << Option.PricingError << endl;

    return 0;

    return 0;
}