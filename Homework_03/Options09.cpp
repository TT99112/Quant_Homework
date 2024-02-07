#include "Options09.h"
#include "BinModel02.h"
#include "BinLattice02.h"
#include <iostream>
#include <cmath>
using namespace std;

//double EurOption::PriceByCRR(BinModel Model) {
//    double q = Model.RiskNeutralProb();
//    int N = GetN();
//    vector<double> Price(N + 1);
//    for (int i = 0; i <= N; i++) {
//        Price[i] = Payoff(Model.S(N, i));
//    }
//    for (int n = N - 1; n >= 0; n--)
//    {
//        for (int i = 0; i <= n; i++)
//        {
//            Price[i] = (q * Price[i + 1] + (1 - q) * Price[i])
//                    / (1 + Model.GetR());
//        }
//    }
//    return Price[0];
//}

//double EurOption::PriceByCRR(BinModel Model, BinLattice<double>& DeltaTree, BinLattice<double>& CashTree) {
//    double q = Model.RiskNeutralProb();
//    int N = GetN();
//    DeltaTree.SetN(N);
//    CashTree.SetN(N);
//    vector<double> Price(N + 1);
//
//    BinLattice<double> PriceTree;
//
//    // Compute option prices at maturity
//    for (int i = 0; i <= N; i++) {
//        Price[i] = Payoff(Model.S(N, i));
//        PriceTree.SetNode(N, i, Price[i]);
//    }
//
//    for (int n = N - 1; n >= 0; n--) {
//        for (int i = 0; i <= n; i++) {
//            double ContVal = (q * Price[i + 1] + (1 - q) * Price[i])
//                             / (1 + Model.GetR());
//            PriceTree.SetNode(n, i, ContVal);
//        }
//        for (int i = 0; i <= n; i++) {
//
//            double Delta = (PriceTree.GetNode(n+1,i+1) - PriceTree.GetNode(n+1,i))/
//                    (Model.S(n + 1, i+1) - Model.S(n + 1, i));
//            DeltaTree.SetNode(n, i, Delta);
//
//            double Cash = (PriceTree.GetNode(n+1,i) - Delta * Model.S(n + 1, i)) / (1 + Model.GetR());
//            CashTree.SetNode(n, i, Cash);
//
//        }
//    }
//    return Price[0];
//}

double EurOption::PriceByCRR(BinModel Model, BinLattice<double>& DeltaTree, BinLattice<double>& CashTree) {
    double q = Model.RiskNeutralProb();
    int N = GetN();
    DeltaTree.SetN(N);
    CashTree.SetN(N);
    BinLattice<double> PriceTree;
    PriceTree.SetN(N);

    // Compute option prices at maturity and store them in PriceTree
    for (int i = 0; i <= N; i++) {
        PriceTree.SetNode(N, i, Payoff(Model.S(N, i)));
    }
    for (int n = N - 1; n >= 0; n--) {
        for (int i = 0; i <= n; i++) {
            double ContVal = (q * PriceTree.GetNode(n + 1, i + 1) + (1 - q) * PriceTree.GetNode(n + 1, i)) / (1 + Model.GetR());
            PriceTree.SetNode(n, i, ContVal);
        }
    }

    // Backward induction to compute replicating strategy
    for (int n = N - 1; n >= 0; n--) {
        // Compute deltas and update option prices
        for (int i = 0; i <= n; i++) {
            double Delta;
            if (n == N-1 && PriceTree.GetNode(n+1, i) > 0) {
                DeltaTree.SetNode(n+1, i, 1.0);
            }
            Delta = (PriceTree.GetNode(n + 1, i + 1) - PriceTree.GetNode(n + 1, i)) / (Model.S(n + 1, i + 1) - Model.S(n + 1, i));
            DeltaTree.SetNode(n, i, Delta);
            double Cash = (PriceTree.GetNode(n + 1, i) - DeltaTree.GetNode(n, i) * Model.S(n + 1, i)) / (1 + Model.GetR());
            CashTree.SetNode(n, i, Cash);
        }
    }
    return PriceTree.GetNode(0, 0);
}

double AmOption::PriceBySnell(BinModel Model,
                              BinLattice<double>& PriceTree,
                              BinLattice<bool>& StoppingTree)
                              {
    double q = Model.RiskNeutralProb();
    int N = GetN();
    PriceTree.SetN(N);
    StoppingTree.SetN(N);
    double ContVal;
    for (int i = 0; i <= N; i++)
    {
        PriceTree.SetNode(N, i, Payoff(Model.S(N, i)));
        StoppingTree.SetNode(N, i, 1);
    }
    for (int n = N - 1; n >= 0; n--) {
        for (int i = 0; i <= n; i++)
        {
            ContVal = (q * PriceTree.GetNode(n + 1, i + 1)
                    + (1 - q) * PriceTree.GetNode(n + 1, i))
                            / (1 + Model.GetR());

            PriceTree.SetNode(n, i, Payoff(Model.S(n, i)));

            StoppingTree.SetNode(n, i, 1);

            double epsilon = 0.01;
            // If ContVal is greater than PriceTree.GetNode(n, i) with precision up to 2 decimal points
            if (round(ContVal * 100) / 100 > round(PriceTree.GetNode(n, i) * 100) / 100 + epsilon)
//            if (ContVal > PriceTree.GetNode(n, i))
            {
                PriceTree.SetNode(n, i, ContVal);
                StoppingTree.SetNode(n, i, 0);
            }
            else if (PriceTree.GetNode(n, i) == 0.0)
            {
                StoppingTree.SetNode(n, i, 0);
            }
        }
    }
    return PriceTree.GetNode(0, 0);
}

int Call::GetInputData() {
    cout << "Enter call option data: " << endl;
    int N;
    cout << "Enter steps to expiry N: "; cin >> N;
    SetN(N);
    cout << "Enter strike price K: "; cin >> K;
    cout << endl;
    return 0;
}

double Call::Payoff(double z) {
    if (z > K)
        return z - K;
    return 0.0;
}

int Put::GetInputData() {
    cout << "Enter put option data: " << endl;
    int N;
    cout << "Enter steps to expiry N: ";
    cin >> N;
    SetN(N);
    cout << "Enter strike price K: ";
    cin >> K;
    cout << endl;
    return 0;
}

double Put::Payoff(double z) {
    if (z < K)
        return K - z;
    return 0.0;
}