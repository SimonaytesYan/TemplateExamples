#pragma once

#include <stdio.h>

#include "Arrays.hpp"

template<int row_number, int column_number>
struct Matrix;

template<int row_number, int column_number, int index>
struct SumMatrix
{
    void operator()(const Matrix<row_number, column_number>& a, 
                    const Matrix<row_number, column_number>& b, 
                          Matrix<row_number, column_number>& res)
    {
        SumMatrix<row_number, column_number, index+1> sum;
        sum(a, b, res);
        a[index].sum(b[index], res[index]);
    }
};

template<int row_number, int column_number>
struct SumMatrix<row_number, column_number, row_number>
{
    void operator()(const Matrix<row_number, column_number>& a, 
                const Matrix<row_number, column_number>& b, 
                      Matrix<row_number, column_number>& res)
    {
    }
};

template<int row_number, int column_number>
struct Matrix
{
    Array<column_number> value[row_number] = {};

    void sum(const Matrix<row_number, column_number>& b, 
                   Matrix<row_number, column_number>& res) const 
    {
        SumMatrix<row_number, column_number, 0> sum;
        sum(*this, b, res);
    }

    Array<column_number> operator[](int index) const
    {
        return value[index];
    }

    Array<column_number>& operator[](int index)
    {
        return value[index];
    }
};
