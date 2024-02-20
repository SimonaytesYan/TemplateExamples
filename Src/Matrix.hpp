#pragma once

#include <stdio.h>

#include "Arrays.hpp"

const int RowNumber = 4;

struct Matrix
{
    Array value[RowNumber] = {};
};

template <int x>
void sum_matrix(const Matrix& a, const Matrix& b, Matrix& c);

template <>
void sum_matrix<RowNumber>(const Matrix& a, const Matrix& b, Matrix& c);

template <int x>
void sum_matrix(const Matrix& a, const Matrix& b, Matrix& c)
{
    sum_matrix<x + 1>(a, b, c);
    sum_array<0>(a.value[x], b.value[x], c.value[x]);
}

template <>
void sum_matrix<RowNumber>(const Matrix& a, const Matrix& b, Matrix& c)
{
}
