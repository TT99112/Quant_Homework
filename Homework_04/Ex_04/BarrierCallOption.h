//
// Created by Tamour on 27/02/2024.
//

#ifndef QUANT_HOMEWORK_BARRIERCALLOPTION_H
#define QUANT_HOMEWORK_BARRIERCALLOPTION_H

#include "PathDepOption04.h"
#include <algorithm> // For max_element

class BarrierCallOption : public PathDepOption {
public:
    double K; // Strike price
    double L; // Barrier level
    BarrierCallOption(double T_, double K_, double L_, int m_) : PathDepOption(), K(K_), L(L_) {
        T = T_;
        m = m_;
    }

    double Payoff(SamplePath& S) override;
};


#endif //QUANT_HOMEWORK_BARRIERCALLOPTION_H
