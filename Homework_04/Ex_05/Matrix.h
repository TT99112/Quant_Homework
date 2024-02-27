//
// Created by Tamour on 27/02/2024.
//

#ifndef QUANT_HOMEWORK_MATRIX_H
#define QUANT_HOMEWORK_MATRIX_H


#include <vector>

using namespace std;
typedef vector<double> Vector;
typedef vector<Vector> Matrix;

Vector operator*(const Matrix& C, const Vector& V);
Vector operator*(const double& a, const Vector& V);
Vector operator+(const double& a, const Vector& V);
Vector operator+(const Vector& V, const Vector& W);
Vector operator*(const Vector& V, const Vector& W);
Vector exp(const Vector& V);
double operator^(const Vector& V, const Vector& W);



#endif //QUANT_HOMEWORK_MATRIX_H
