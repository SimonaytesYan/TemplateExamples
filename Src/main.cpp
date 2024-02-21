#include "Templates.hpp"

#include "Arrays.hpp"

#include "Matrix.hpp"

const int ArraySize = 4;

const int Columns = 3;
const int Rows    = 2;

void TestInt()
{
    int res_int = my_sum<int, int>(1, 2, 3, 4, 5, 6, 7, 8, 9);

    printf("INT:\n");
    printf("%d\n", res_int);
}

void TestArray()
{
    const Array<ArraySize> a = {0, 1, 2, 3};
    const Array<ArraySize> b = {1, 2, 3, 4};
    Array<ArraySize> res_array;
    a.sum(b, res_array);

    printf("ARRAY:\n");
    for (int i = 0; i < ArraySize; i++)
        printf("%d ", res_array[i]);
    printf("\n");
}

void TestMatrix()
{
    Matrix<Rows, Columns> res_matrix;
    const Matrix<Rows, Columns> a = {Array<Columns>{0, 1, 2},
                                     Array<Columns>{3, 4, 5}};
    const Matrix<Rows, Columns> b = {Array<Columns>{2, 3, 4},
                                     Array<Columns>{5, 6, 7}};

    a.sum(b, res_matrix);

    printf("MATRIX:\n");
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Columns; j++)
            printf("%d ", res_matrix[i][j]);
        printf("\n");
    }
}

int main()
{
    TestInt();
    TestArray();
    TestMatrix();
}