//
// Created by Tamour on 06/02/2024.
//

#include "Options06.h"
#include "BinModel02.h"
#include <iostream>

double EurOption::PriceByCRR(BinModel Model)
{
    double q = Model.RiskNeutralProb();
    double Price[N + 1];

    for (int i = 0; i <= N; i++)
    {
        Price[i] = Payoff(Model.S(N, i));
    }

    for (int n = N - 1; n >= 0; n--)
    {
        for (int i = 0; i <= n; i++)
        {
            Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / (1 + Model.GetR());
        }
    }
    return Price[0];
}

int Call::GetInputData()
{
    std::cout << "Enter call option data: " << std::endl;
    int N;
    std::cout << "Enter steps to expiry N: ";
    std::cin >> N;
    SetN(N);
    std::cout << "Enter strike price K: ";
    std::cin >> K;
    std::cout << std::endl;
    return 0;
}

double Call::Payoff(double z)
{
    if (z > K)
        return z - K;
    return 0.0;
}

int Put::GetInputData()
{
    std::cout << "Enter put option data: " << std::endl;
    int N;
    std::cout << "Enter steps to expiry N: ";
    std::cin >> N;
    SetN(N);
    std::cout << "Enter strike price K: ";
    std::cin >> K;
    std::cout << std::endl;
    return 0;
}

double Put::Payoff(double z)
{
    if (z < K)
        return K - z;
    return 0.0;
}

//DigitalDouble

int DoubleDigital::GetInputData()
{
    std::cout << "Enter double digital option data: " << std::endl;
    int N;
    std::cout << "Enter steps to expiry N: ";
    std::cin >> N;
    SetN(N);
    std::cout << "Enter lower strike price K1: ";
    std::cin >> K1;
    std::cout << "Enter upper strike price K2: ";
    std::cin >> K2;
    std::cout << std::endl;
    return 0;
}

double DoubleDigital::Payoff(double z) {
    if (z > K1 && z < K2)
        return 1.0;
    return 0.0;
}



