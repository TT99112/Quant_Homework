//
// Created by Tamour on 06/02/2024.
//

#include "BinLattice02.h"
#include "BinModel02.h"
#include "Options09.h"
#include <iostream>


//    double S0 = 100;
//    double U = 0.05;
//    double D = -0.05;
//    double R = 0.00;
//    double N = 4
//    double K = 100

using namespace std;

int main() {
//    BinModel Model;
//    if (Model.GetInputData() == 1)
//        return 1;

//    Put Option;
//    Option.GetInputData();
//
//    BinLattice<double> PriceTree;
//    BinLattice<bool> StoppingTree;
//
//    Option.PriceBySnell(Model, PriceTree, StoppingTree);
//
//    cout << "American put prices: " << endl << endl;
//    PriceTree.Display();
//
//    cout << "American put exercise policy: " << endl << endl;
//    StoppingTree.Display();

    //Exercise 3-1
    BinModel Model;
    if (Model.GetInputData() == 1)
        return 1;

    Call Option;
    Option.GetInputData();

    BinLattice<double> MoneyMarketTree;
    BinLattice<double> StockPositionTree;

    double optionPrice = Option.PriceByCRR(Model, MoneyMarketTree, StockPositionTree);

    // Displaying the replicating strategy
    StockPositionTree.Display();
    MoneyMarketTree.Display();


    cout << "European call price: " << optionPrice << endl;

    return 0;
}