//
// Created by mauri on 13.10.17.
//

#ifndef SAMPLE_PROJECT_MATRIX_MATRIX_H
#define SAMPLE_PROJECT_MATRIX_MATRIX_H


#include <vector>

class Matrix {
private:
    unsigned long col, row;
public:
    unsigned long getCol() const;

    unsigned long getRow() const;
    //std::vector<std::vector<int>> mat_num(, std::vector<int>(row));
public:
    std::vector<std::vector<int>> *matrix;

    Matrix(unsigned long x, unsigned long y);

    bool areSameSize(const Matrix &matrix);

    bool canMultiply(const Matrix &matrix);

    Matrix *operator+(const Matrix &matrix);

    Matrix *operator*(const Matrix &matrix);

    Matrix *operator-(const Matrix &matrix);

    void printMatrix();

};


#endif //SAMPLE_PROJECT_MATRIX_MATRIX_H
