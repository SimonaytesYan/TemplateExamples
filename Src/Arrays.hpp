#pragma once

#include <stdio.h>

const int kArraySize = 4;

struct Array
{
    int value[kArraySize];
};

template <int id>
void sum_array(const Array& a, const Array& b, Array& c);

template <>
void sum_array<kArraySize>(const Array& a, const Array& b, Array& c);

template <int id>
void sum_array(const Array& a, const Array& b, Array& c)
{
    sum_array<id+1>(a, b, c);
    c.value[id] = a.value[id] + b.value[id];
}

template <>
void sum_array<kArraySize>(const Array& a, const Array& b, Array& c)
{
}
