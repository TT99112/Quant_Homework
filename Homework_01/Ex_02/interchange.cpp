//
// Created by Tamour on 06/02/2024.
//

#include <iostream>
#include "interchange.h"

void interchange(double& a, double& b)
{
    double c = a;
    a = b;
    b = c;
}