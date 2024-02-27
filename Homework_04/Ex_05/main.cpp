//
// Created by Tamour on 26/02/2024.
//

#include <iostream>
#include "PathDepOption05.h"
using namespace std;

int main() {
    int d = 3;
    Vector S0(d);
    S0[0] = 40.0;
    S0[1] = 60.0;
    S0[2] = 100.0;
    double r = 0.03;
    Matrix C(d);
    for (int i = 0; i < d; i++)
        C[i].resize(d);
    C[0][0] = 0.1; C[0][1] = -0.1; C[0][2] = 0.0;
    C[1][0] = -0.1; C[1][1] = 0.2; C[1][2] = 0.0;
    C[2][0] = 0.0; C[2][1] = 0.0; C[2][2] = 0.3;

    BSModel Model(S0, r, C);
    double T = 1.0 / 12.0;
    int m = 30;

    // Compute K_j for each asset
    double sum_S0 = 0.0;
    for (int j = 0; j < d; j++) {
        sum_S0 += S0[j];
    }
    Vector K_vector(d);
    for (int j = 0; j < d; j++) {
        K_vector[j] = 200.0 * (S0[j] / sum_S0);
    }

    // Create ArthmAsianCall option
    double K_arithm = 200.0;
    ArthmAsianCall Option_arithm(T, K_arithm, m);

    // Create BasketCallOption option with adjusted strike prices K_j
    BasketCallOption Option_basket(T, K_vector, m);

    long N = 30000;

    // Price the options using Monte Carlo
    double price_arithm = Option_arithm.PriceByMC(Model, N);
    double price_basket = Option_basket.PriceByMC(Model, N);

    // Output results
    cout << "Arithmetic Basket Call Price = " << price_arithm << endl;
    cout << "European Basket Call Option Price: " << price_basket << endl;

    return 0;
}