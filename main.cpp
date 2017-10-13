#include <iostream>
#include "Matrix.h"

/**
 * Write a program which performs addition, subtraction, multiplication of matrices.
 * The dimensions of both the matrices would be specified by the user (dynamic memory allocation required).
 * Use of structure or a class to define the matrix would be a good idea.
 * @return
 */
int main() {
    unsigned long x, y;
    std::cout << "Please insert columns size 1st matrix: ";
    std::cin >> x;
    std::cout << std::endl;
    std::cout << "Please insert rows size 1st matrix: ";
    std::cin >> y;
    std::cout << std::endl;
    auto *first = new Matrix(x, y);
    std::cout << "Please insert columns size 1st matrix: ";
    std::cin >> x;
    std::cout << std::endl;
    std::cout << "Please insert rows size 1st matrix: ";
    std::cin >> y;
    std::cout << std::endl;
    auto *second = new Matrix(x, y);
    for (unsigned int i = 0; i < first->getCol(); ++i) {
        for (unsigned int j = 0; j < first->getRow(); j++) {
            first->matrix->at(i)[j] = i;
            second->matrix->at(i)[j] = j;
        }
    }
    std::cout << "First matrix" << std::endl;
    first->printMatrix();
    std::cout << "Second matrix" << std::endl;
    second->printMatrix();
    Matrix *result_sum = *first + *second;
    if (result_sum != nullptr) {
        std::cout << "Sum result" << std::endl;
        result_sum->printMatrix();
    }
    Matrix *result_sub = *second - *first;
    if (result_sub != nullptr) {
        std::cout << "Subtraction result" << std::endl;
        result_sub->printMatrix();
    }
    Matrix *result_mul = *second * *first;
    if (result_mul != nullptr) {
        std::cout << "Multiplication result" << std::endl;
        result_mul->printMatrix();
    }
    return 0;
}