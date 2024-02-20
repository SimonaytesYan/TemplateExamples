#include "Templates.hpp"

#include "Arrays.hpp"

// #include "Matrix.hpp"

const int ArraySize = 4;

void TestInt()
{
    int res_int = my_sum<int, int>(1, 2, 3, 4, 5, 6, 7, 8, 9);

    printf("INT:\n");
    printf("%d\n", res_int);
}

void TestArray()
{
    Array<ArraySize> res_array;
    const Array<ArraySize> a = {0, 1, 2, 3};
    const Array<ArraySize> b = {1, 2, 3, 4};
    
    a.sum_array<0>(b, res_array);

    printf("ARRAY:\n");
    for (int i = 0; i < kArraySize; i++)
        printf("%d ", res_array.value[i]);
    printf("\n");
}

// void TestMatrix()
// {
//     Matrix res_matrix;
//     const Matrix a = {Array{0,   1,  2,  3},
//                       Array{4,   5,  6,  7},
//                       Array{8,   9, 10, 11},
//                       Array{12, 13, 14, 15}};
//     const Matrix b = {Array{2,   3,  4,  5},
//                       Array{6,   7,  8,  9},
//                       Array{10, 11, 12, 13},
//                       Array{14, 15, 16, 17}};
//     sum_matrix<0>(a, b, res_matrix);

//     printf("MATRIX:\n");
//     for (int i = 0; i < RowNumber; i++)
//     {
//         for (int j = 0; j < kArraySize; j++)
//             printf("%d\t", res_matrix.value[i].value[j]);
//         printf("\n");
//     }
// }

int main()
{
    TestInt();
    TestArray();
    // TestMatrix();
}