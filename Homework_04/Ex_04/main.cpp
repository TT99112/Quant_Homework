//
// Created by Tamour on 25/02/2024.
//

#include <iostream>
#include "PathDepOption04.h"
#include "GmtrAsianCall.h"
#include "EurCall.h"
#include "BarrierCallOption.h"

using namespace std;


int main() {
    double S0 = 100.0, r = 0.03, sigma = 0.2;
    BSModel Model(S0, r, sigma);
    double T = 1.0 / 12.0, K = 100.0;
    int m = 30;

    ArithmAsianCall Option(T, K, m);
    GmtrAsianCall CVOption(T, K, m);

    long N = 30000;

    Option.PriceByVarRedMC(Model, N, CVOption);
    cout << "Arithmetic call price = " << Option.Price << endl
         << "Error = " << Option.PricingError << endl;

    Option.PriceByMC(Model, N);
    cout << "Price by direct MC = " << Option.Price << endl
         << "MC Error = " << Option.PricingError << endl;

    double L = 105.0; // Define the barrier level
    BarrierCallOption barrierOption(T, K, L, m);
    barrierOption.CalculateEurCallPrice(Model); // Calculate European Call price internally

    barrierOption.PriceByMC(Model, N);
    cout << "Barrier Call Option price = " << barrierOption.Price << endl
         << "Error = " << barrierOption.PricingError << endl;

    return 0;
}