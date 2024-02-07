#include <iostream>
#include "BinModel02.h"
#include "Options06.h"

//
// Created by Tamour on 05/02/2024.
//
int main()
{
    BinModel Model;

//    double S0 = 100;
//    double U = 0.05;
//    double D = -0.05;
//    double R = 0.00;
//    double N = 6
//    double K = 200


    if (Model.GetInputData() == 1)
        return 1;

    Call Option1;
    Option1.GetInputData();

    std::cout << "European call option price = "
              << Option1.PriceByCRR(Model)
              << std::endl << std::endl;

    Put Option2;
    Option2.GetInputData();

    std::cout << "European put option price = "
              << Option2.PriceByCRR(Model)
              << std::endl << std::endl;

    DoubleDigital doubleDigitalOption;
    doubleDigitalOption.GetInputData();

    std::cout << "Double digital Price = "
              << doubleDigitalOption.PriceByCRR(Model)
              << std::endl << std::endl;

    return 0;
}