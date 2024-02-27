//
// Created by Tamour on 27/02/2024.
//

#include "BarrierCallOption.h"

double BarrierCallOption::Payoff(SamplePath& S) {
    double MaxS = *std::max_element(S.begin(), S.end());
    if (MaxS <= L) {
        double finalPrice = S.back();
        return std::max(finalPrice - K, 0.0);
    } else {
        return 0.0; // Option expires worthless if the barrier is breached
    }
}