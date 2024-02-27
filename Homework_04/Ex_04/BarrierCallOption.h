//
// Created by Tamour on 26/02/2024.
//

#ifndef QUANT_HOMEWORK_BARRIERCALLOPTION_H
#define QUANT_HOMEWORK_BARRIERCALLOPTION_H

#include "PathDepOption04.h"

class BarrierCallOption : public PathDepOption{
public:
    double K,L;
    
    BarrierCallOption(double T_, double K_, double L_, int m_) { T = T_; K = K_; L = L_, m = m_; }
    double Payoff(SamplePath& S);
    double PriceByBSFormula(BSModel Model);
};


#endif //QUANT_HOMEWORK_BARRIERCALLOPTION_H
