#ifndef QUANT_HOMEWORK_OPTIONS09_H
#define QUANT_HOMEWORK_OPTIONS09_H

#include "BinLattice02.h"
#include "BinModel02.h"

class Option {
private:
    int N; // steps to expiry

public:
    void SetN(int N_) {N=N_;}
    int GetN() {return N;}
    virtual double Payoff(double z) = 0;
};

class EurOption : public virtual Option {
public:
    double PriceByCRR(BinModel Model, BinLattice<double> &DeltaTree, BinLattice<double> &CashPositionTree);
};

class AmOption : public virtual Option {
public:
    // pricing American option
    double PriceBySnell(BinModel Model,
                        BinLattice<double>& PriceTree,
                        BinLattice<bool>& StoppingTree);
};

class Call : public EurOption, public AmOption {
private:
    double K;
public:
    int GetInputData();
    double Payoff(double z);
};

class Put : public EurOption, public AmOption {
private:
    double K;

public:
    int GetInputData();
    double Payoff(double z);
};

class KO_Call : public EurOption, public AmOption {
private:
    double K;
    double Barrier;

public:
    int GetInputData();
    double Payoff(double z);
};

class KI_Call : public EurOption, public AmOption {
private:
    double K;
    double Barrier;

public:
    int GetInputData();
    double Payoff(double z);
};

class KO_Put : public EurOption, public AmOption {
private:
    double K;e
    double Barrier;

public:
    int GetInputData();
    double Payoff(double z);
};

class KI_Put : public EurOption, public AmOption {
private:
    double K;
    double Barrier;

public:
    int GetInputData();
    double Payoff(double z);
};

#endif //QUANT_HOMEWORK_OPTIONS09_H
