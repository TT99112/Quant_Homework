//
// Created by Tamour on 06/02/2024.
//

#ifndef QUANT_HOMEWORK_BINMODEL02_H
#define QUANT_HOMEWORK_BINMODEL02_H


class BinModel
{
private:
    double S0;
    double U;
    double D;
    double R;

public:
    double RiskNeutralProb();
    double S(int n, int i);
    int GetInputData();
    double GetR();
};



#endif //QUANT_HOMEWORK_BINMODEL02_H
