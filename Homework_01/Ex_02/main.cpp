//
// Created by Tamour on 06/02/2024.
//
#include "bubbleSort.h"
#include <iostream>
int main() {
    const int N = 6;
    double arr[N] = {64.0, 34.0, 25.0, 12.0, 22.0, 11.0};

    std::cout << "Before sorting:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Use bubbleSort function
    bubbleSort(arr, N);

    std::cout << "After sorting:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
