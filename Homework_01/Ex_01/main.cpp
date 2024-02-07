#include <iostream>
#include "interchange.h"

//
// Created by Tamour on 05/02/2024.
//


int main() {
    double a = 1.0;
    double b = 2.0;
    std::cout << "Before interchange:" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    std::cout << "After interchange:" << std::endl;

    interchange(a, b);

    return 0;
}