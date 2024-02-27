//
// Created by Tamour on 27/02/2024.
//

#include "BarrierCallOption.h"

void BarrierCallOption::CalculateEurCallPrice(const BSModel& Model) {
    eurCall = new EurCall(T, K);
    eurCallPrice = eurCall->PriceByBSFormula(Model.S0, Model.sigma, Model.r);
}

double BarrierCallOption::Payoff(SamplePath& S) {
    double payoff = 0.0;
    double MaxS = *std::max_element(S.begin(), S.end());
    if (MaxS <= L) {
        double finalPrice = S.back();
        payoff = std::max(finalPrice - K, 0.0); // Barrier option payoff
    }

    // Calculate European Call payoff for the same path
    double eurCallPayoff = std::max(S.back() - K, 0.0);

    // Adjust the barrier option payoff using the control variate technique with the European Call price
    payoff += (eurCallPrice - eurCallPayoff); // Use the member variable

    return payoff;
}