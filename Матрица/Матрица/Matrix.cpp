#include "Matrix.h"
Matrix::Matrix()
{
    this->mat = NULL;
    this->rows = 0;
    this->cols = 0;
}
Matrix::Matrix(const unsigned int rows, const unsigned int cols)
{
    this->rows = rows;
    this->cols = cols;
    this->mat = new int* [this->rows];
    for (unsigned int i = 0;i < this->rows;i++)
        this->mat[i] = new int[this->cols];
}
Matrix::~Matrix()
{
    for (unsigned int i = 0;i < this->rows;i++)
        delete[] this->mat[i];
    delete[] this->mat;
}
void Matrix::setMatrix(const char* str)
{
    unsigned int str_counter = 0;
    if (strlen(str) == this->cols * this->rows)
    {
        for (unsigned int i = 0;i < this->rows;i++)
        {
            for (unsigned int j = 0;j < this->cols;j++)
            {
                this->mat[i][j] = str[str_counter] - 48;
                str_counter++;
            }
        }
    }
    else
        cout << "Error! Wrong values..." << endl;
}
int** Matrix::getMatrix()
{
    return this->mat;
}
void Matrix::print()
{
    if (this->cols > 0 && this->rows > 0)
    {
        for (unsigned int i = 0;i < this->rows;i++)
        {
            for (unsigned int j = 0;j < this->cols;j++)
            {
                cout << this->mat[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    else
        cout << "NULL" << endl;
}
