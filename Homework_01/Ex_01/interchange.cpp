//
// Created by Tamour on 06/02/2024.
//

#include <iostream>

void interchange(double& a, double& b)
{
    double c = a;
    a = b;
    b = c;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
}