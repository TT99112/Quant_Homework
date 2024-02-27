//
// Created by Tamour on 25/02/2024.
//

#include <iostream>
#include "PathDepOption04.h"
#include "GmtrAsianCall.h"
#include "BarrierCallOption.h"
#include "EurCall.h"

using namespace std;

int main() {
    double S0 = 100.0, r = 0.03, sigma = 0.2;
    BSModel Model(S0, r, sigma);
    double T = 1.0 / 12.0, K = 100.0;
    int m = 30;

    ArithmeticAsianCall Option(T, K, m);
    GmtrAsianCall CVOption(T, K, m);

    long N = 30000;

    Option.PriceByVarRedMC(Model, N, CVOption);
    cout << "Arithmetic call price = " << Option.Price << endl
         << "Error = " << Option.PricingError << endl;

    Option.PriceByMC(Model, N);
    cout << "Price by direct MC = " << Option.Price << endl
         << "MC Error = " << Option.PricingError << endl;

    double L = 110.0; // Example barrier level
    BarrierCallOption BarrierOption(T, K, L, m);
    EurCall EuroOption(T, K);

    double barrierOptionPrice = BarrierOption.PriceByVarRedMC(Model, N, EuroOption);
    cout << "Barrier call price = " << barrierOptionPrice << endl
         << "Error = " << BarrierOption.PricingError << endl;
    return 0;
}