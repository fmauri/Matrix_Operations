#include <iostream>
#include "Matrix.h"

/**
 * Write a program which performs addition, subtraction, multiplication of matrices.
 * The dimensions of both the matrices would be specified by the user (dynamic memory allocation required).
 * Use of structure or a class to define the matrix would be a good idea.
 * @return
 */
int main() {
    unsigned long x = 3, y = 3;
    auto *first = new Matrix(x, y);
    auto *second = new Matrix(x, y);
    for (unsigned int i = 0; i < first->getCol(); ++i) {
        for (unsigned int j = 0; j < first->getRow(); j++) {
            first->matrix->at(i)[j] = i;
            second->matrix->at(i)[j] = j;
        }
    }
    first->printMatrix();
    std::cout << std::endl;
    second->printMatrix();
    std::cout << std::endl;
    Matrix *result_sum = *first + *second;
    result_sum->printMatrix();
    std::cout << std::endl;
    Matrix *result_sub = *result_sum - *first;
    result_sub->printMatrix();
    std::cout << std::endl;
    Matrix *result_mul = *second * *first;
    result_mul->printMatrix();
    return 0;
}