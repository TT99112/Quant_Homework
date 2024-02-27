//
// Created by Tamour on 27/02/2024.
//

#ifndef QUANT_HOMEWORK_BARRIERCALLOPTION_H
#define QUANT_HOMEWORK_BARRIERCALLOPTION_H

#include "PathDepOption04.h"
#include <algorithm> // For max_element
#include "EurCall.h"

class BarrierCallOption : public PathDepOption {
public:
    double K, L;
    EurCall* eurCall; // Dynamically allocated to adjust for different market conditions
    double eurCallPrice; // To store calculated European Call price internally

    BarrierCallOption(double T_, double K_, double L_, int m_)
            : PathDepOption(), K(K_), L(L_), eurCall(nullptr), eurCallPrice(0.0) {
        T = T_;
        m = m_;
    }

    ~BarrierCallOption() {
        if (eurCall) delete eurCall;
    }

    void CalculateEurCallPrice(const BSModel& Model);

    double Payoff(SamplePath& S) override;
};


#endif //QUANT_HOMEWORK_BARRIERCALLOPTION_H
