#pragma once

#include <stdio.h>
 
template<int length>
struct Array;

template<int length, int index>
struct SumArray
{
    void operator()(const Array<length>& a, const Array<length>& b, Array<length>& res)
    {
        SumArray<length, index+1> sum;
        sum(a, b, res);
        res[index] = a[index] + b[index];
    }
};

template<int length>
struct SumArray<length, length>
{
    void operator()(const Array<length>& a, const Array<length>& b, Array<length>& res)
    {
    }
};

template<int length>
struct Array
{
    int value[length];

    void sum(const Array<length>& b, Array<length>& res) const 
    {
        SumArray<length, 0> sum;
        sum(*this, b, res);
    }

    int operator[](int index) const
    {
        return value[index];
    }

    int& operator[](int index)
    {
        return value[index];
    }
};
