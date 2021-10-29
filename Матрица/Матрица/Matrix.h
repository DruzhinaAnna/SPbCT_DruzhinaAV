#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
class Matrix
{
private:
    int** mat;
    unsigned int rows;
    unsigned int cols;
public:
    Matrix();
    Matrix(const unsigned int, const unsigned int);
    ~Matrix();
    void setMatrix(const char*);
    int** getMatrix();
    void print();
};
#endif // MATRIX_H

