//
// Created by Tamour on 26/02/2024.
//

// BarrierCallOption.cpp
#include "BarrierCallOption.h"
#include <algorithm> // For max_element

double BarrierCallOption::Payoff(SamplePath& S) {
    double maxS = *max_element(S.begin(), S.end());
    if (maxS > L) return 0.0; // Barrier not breached
    else return max(S.back() - K, 0.0); // Standard call payoff
}