//
// Created by Tamour on 06/02/2024.
//
#include "BinModel02.h"
#include <iostream>
#include <cmath>

using namespace std;

double BinModel::RiskNeutralProb()
{
    return (R - D) / (U - D);
}

double BinModel::S(int n, int i)
{
    return S0 * pow(1 + U, i) * pow(1 + D, n - i);
}

int BinModel::GetInputData()
{
    // entering data
    cout << "Enter S0: ";
    cin >> S0;
    cout << "Enter U: ";
    cin >> U;
    cout << "Enter D: ";
    cin >> D;
    cout << "Enter R: ";
    cin >> R;
    cout << endl;

//S0=100
//sigma=2
//r=0.03
//dt = 1

/*
    cout << "Enter r: ";
    cin >> r;
    cout << "Enter sigma: ";
    cin >> sigma;
    cout << "Enter dt: ";
    cin >> dt;
    cout << endl;


    U = exp((r + 0.5*sigma*sigma ))*dt + sigma * sqrt(dt) - 1.0;
    D = exp((r + 0.5*sigma*sigma ))*dt - sigma * sqrt(dt) - 1.0;
    R = exp(r*dt) - 1.0;
    cout << U << endl;
    cout << D << endl;
    cout << R << endl;
*/


    // making sure that 0 < S0, -1 < D < U, -1 < R
    if (S0 <= 0.0 || U <= -1.0 || D <= -1.0 || U <= D || R <= -1.0)
    {
        cout << "Illegal data ranges" << endl;
        cout << "Terminating program" << endl;
        return 1;
    }

    // checking for arbitrage
    if (R >= U || R <= D)
    {
        cout << "Arbitrage exists" << endl;
        cout << "Terminating program" << endl;
        return 1;
    }

    cout << "Input data checked" << endl;
    cout << "There is no arbitrage" << endl << endl;
    return 0;
}

double BinModel::GetR()
{
    return R;
}

double BinModel::getR() {
    return r;
}

double BinModel::GetS0(){
    return S0;
}

double BinModel::GetSigma(){
    return sigma;
}
