#pragma once

#include <stdio.h>

template<int length>
struct Array
{
    int value[length];

    template<int id>
    void sum_array(const Array<length>& b, Array<length>& c) const
    {
        sum_array<id+1>(b, c);
        c.value[id] = value[id] + b.value[id];
    };


    template<>
    void sum_array<length>(const Array<length>& b, Array<length>& c) const
    {
    }
};
