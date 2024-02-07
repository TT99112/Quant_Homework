//
// Created by Tamour on 06/02/2024.
//

#include "bubblesort.h"

void bubbleSort(double a[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                interchange(a[j], a[j + 1]);
            }
        }
    }
}

