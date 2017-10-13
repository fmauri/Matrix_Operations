//
// Created by mauri on 13.10.17.
//

#include <iostream>
#include "Matrix.h"

Matrix::Matrix(unsigned long x, unsigned long y) {
    this->col = x;
    this->row = y;
    this->matrix = new std::vector<std::vector<int>>(x, std::vector<int>(y));
}

bool Matrix::areSameSize(const Matrix &matrix) {
    return (matrix.col == this->col && matrix.row == this->row);
}

bool Matrix::canMultiply(const Matrix &matrix) {
    return (matrix.getCol() == this->row);
}

Matrix *Matrix::operator+(const Matrix &matrix) {
    if (areSameSize(matrix)) {
        auto *newM = new Matrix(this->col, this->row);
        for (unsigned long i = 0; i < this->col; ++i) {
            for (unsigned long j = 0; j < this->row; j++) {
                newM->matrix->at(i)[j] = this->matrix->at(i)[j] + matrix.matrix->at(i)[j];
            }
        }
        return newM;
    }
    std::cout << "Wrong Dimensions" << std::endl;
    return nullptr;
}

Matrix *Matrix::operator-(const Matrix &matrix) {
    if (areSameSize(matrix)) {
        auto *newM = new Matrix(this->col, this->row);
        for (unsigned long i = 0; i < this->col; ++i) {
            for (unsigned long j = 0; j < this->row; j++) {
                newM->matrix->at(i)[j] = this->matrix->at(i)[j] - matrix.matrix->at(i)[j];
            }
        }
        return newM;
    }
    std::cout << "Wrong Dimensions" << std::endl;
    return nullptr;
}

Matrix *Matrix::operator*(const Matrix &matrix) {
    if (canMultiply(matrix)) {
        auto *newM = new Matrix(matrix.getCol(), this->row);
        for (unsigned int i = 0; i < matrix.getCol(); ++i)
            for (unsigned j = 0; j < this->row; ++j) {
                newM->matrix->at(i)[j] = 0;
            }
        for (unsigned long x = 0; x < matrix.getCol(); ++x) {
            for (unsigned long y = 0; y < this->row; ++y) {
                for (unsigned int z = 0; z < this->col; ++z) {
                    newM->matrix->at(x)[y] += matrix.matrix->at(x)[z] * this->matrix->at(z)[y];;
                }
            }
        }
        return newM;
    }
    std::cout << "Wrong Dimensions" << std::endl;
    return nullptr;
}

void Matrix::printMatrix() {
    for (unsigned int i = 0; i < this->col; ++i) {
        for (unsigned int j = 0; j < this->row; j++) {
            std::cout << this->matrix->at(i)[j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

unsigned long Matrix::getCol() const {
    return col;
}

unsigned long Matrix::getRow() const {
    return row;
}
