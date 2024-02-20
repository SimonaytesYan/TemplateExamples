#include "Templates.hpp"

#include "Arrays.hpp"

#include "Matrix.hpp"

void TestInt()
{
    int res_int = my_sum<int, int>(1, 2, 3, 4, 5, 6, 7, 8, 9);
    printf("%d\n", res_int);
}

void TestArray()
{
    Array res_array;
    const Array a = {0, 1, 2, 3, 4};
    const Array b = {1, 2, 3, 4, 5};
    
    sum_array<0>(a, b, res_array);

    for (int i = 0; i < kArraySize; i++)
        printf("%d ", res_array.value[i]);
    printf("\n");
}

// void TestMatrix()
// {
//     Matrix res_matrix = {};

// }

int main()
{
    TestInt();
    TestArray();
    // TestMatrix();
}