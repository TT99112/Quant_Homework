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

    double sigma;
    double r;
    double dt;

public:
    double RiskNeutralProb();
    double S(int n, int i);
    int GetInputData();
    double GetR();

    double getR();
    void SetDt(double dt_) { dt = dt_; }

    double GetS0();

    double GetSigma();
};



#endif //QUANT_HOMEWORK_BINMODEL02_H
