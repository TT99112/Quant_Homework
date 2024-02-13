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
    /*
    BinModel Model;
    if (Model.GetInputData() == 1)
        return 1;

    Call Call_Option;
    Call_Option.GetInputData();

    Put Put_Option;
    Put_Option.GetInputData();

    BinLattice<double> callOptionPriceTree;
    BinLattice<bool> callOptionStoppingTree;
    BinLattice<double> callOptionDeltaTree;
    BinLattice<double> callOptionCashTree;

    BinLattice<double> putOptionPriceTree;
    BinLattice<bool> putOptionStoppingTree;
    BinLattice<double> putOptionDeltaTree;
    BinLattice<double> putOptionCashTree;

    double americanCallOptionPrice = Call_Option.PriceBySnell(Model, callOptionPriceTree, callOptionStoppingTree);
    double americanPutOptionPrice = Put_Option.PriceBySnell(Model, putOptionPriceTree, putOptionStoppingTree);

    double europeanCallOptionPrice = Call_Option.PriceByCRR(Model, callOptionDeltaTree, callOptionCashTree);
    double europeanPutOptionPrice = Put_Option.PriceByCRR(Model, putOptionDeltaTree, putOptionCashTree);

    cout << "American Call prices: " << endl << endl;
    callOptionPriceTree.Display();

    cout << "American Call exercise policy: " << endl << endl;
    callOptionStoppingTree.Display();

    cout << "American Call Option price: " << americanCallOptionPrice << endl;


    cout << "American Put prices: " << endl << endl;
    putOptionPriceTree.Display();

    cout << "American Put exercise policy: " << endl << endl;
    putOptionStoppingTree.Display();

    cout << "American Put Option price: " << americanPutOptionPrice << endl;


    cout << "European Call Option Delta Tree: " << endl << endl;
    callOptionDeltaTree.Display();

    cout << "European Call Option Cash Tree: " << endl << endl;
    callOptionCashTree.Display();

    cout << "European Call price: " << europeanCallOptionPrice << endl;



    cout << "European Put Option Delta Tree: " << endl << endl;
    putOptionDeltaTree.Display();

    cout << "European Put Option Cash Tree: " << endl << endl;
    putOptionCashTree.Display();

    cout << "European Put price: " << europeanPutOptionPrice << endl;
*/

    BinModel Model;
    if (Model.GetInputData() == 1)
        return 1;

    Call Call_Option;
    Call_Option.GetInputData();

    Put Put_Option;
    Put_Option.GetInputData();

    BinLattice<double> callOptionPriceTree;
    BinLattice<bool> callOptionStoppingTree;
    BinLattice<double> callOptionDeltaTree;
    BinLattice<double> callOptionCashTree;

    BinLattice<double> putOptionPriceTree;
    BinLattice<bool> putOptionStoppingTree;
    BinLattice<double> putOptionDeltaTree;
    BinLattice<double> putOptionCashTree;

    BinLattice<double> KO_Call_PriceTree;
    BinLattice<bool> KO_Call_StoppingTree;
    BinLattice<double> KO_Call_DeltaTree;
    BinLattice<double> KO_Call_CashTree;

    BinLattice<double> KI_Call_PriceTree;
    BinLattice<bool> KI_Call_StoppingTree;
    BinLattice<double> KI_Call_DeltaTree;
    BinLattice<double> KI_Call_CashTree;

    BinLattice<double> KO_Put_PriceTree;
    BinLattice<bool> KO_Put_StoppingTree;
    BinLattice<double> KO_Put_DeltaTree;
    BinLattice<double> KO_Put_CashTree;

    BinLattice<double> KI_Put_PriceTree;
    BinLattice<bool> KI_Put_StoppingTree;
    BinLattice<double> KI_Put_DeltaTree;
    BinLattice<double> KI_Put_CashTree;

    KO_Call KO_Call_Option;
    KO_Call_Option.GetInputData();

    KO_Put KO_Put_Option;
    KO_Put_Option.GetInputData();

    KI_Call KI_Call_Option;
    KI_Call_Option.GetInputData();

    KI_Put KI_Put_Option;
    KI_Put_Option.GetInputData();

    double KO_Call_Price = KO_Call_Option.PriceByCRR(Model, callOptionDeltaTree, callOptionCashTree);
    double KO_Put_Price = KO_Put_Option.PriceByCRR(Model, putOptionDeltaTree, putOptionCashTree);
    double KI_Call_Price = KI_Call_Option.PriceByCRR(Model, callOptionDeltaTree, callOptionCashTree);
    double KI_Put_Price = KI_Put_Option.PriceByCRR(Model, putOptionDeltaTree, putOptionCashTree);

    cout << "European Call KO price: " << KO_Call_Price << endl;
    cout << "European Put KO price: " << KO_Put_Price << endl;
    cout << "European Call KI price: " << KI_Call_Price << endl;
    cout << "European Put KI price: " << KI_Put_Price << endl;

    double americanKOCallOptionPrice = KO_Call_Option.PriceBySnell(Model, KO_Call_PriceTree, KO_Call_StoppingTree);
    double americanKOPutOptionPrice = KO_Put_Option.PriceBySnell(Model, KO_Put_PriceTree, KO_Put_StoppingTree);
    double americanKICallOptionPrice = KI_Call_Option.PriceBySnell(Model, KI_Call_PriceTree, KI_Call_StoppingTree);
    double americanKIPutOptionPrice = KI_Put_Option.PriceBySnell(Model, KI_Put_PriceTree, KI_Put_StoppingTree);

    cout << "American Call KO price: " << americanKOCallOptionPrice << endl;
    cout << "American Put KO price: " << americanKOPutOptionPrice << endl;
    cout << "American Call KI price: " << americanKICallOptionPrice << endl;
    cout << "American Put KI price: " << americanKIPutOptionPrice << endl;



    return 0;
}