#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

float **matrix(uint64_t rows, uint64_t cols)
{
    float **m = (float **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++)
    {
        m[i] = (float *)malloc(sizeof(float) * cols);
    }

    return m;
}

void clear(int rows, float **matrix)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

float **product(float **matrix_a, int rows_a, int cols_a, float **matrix_b, int rows_b, int cols_b)
{
    if (cols_a != rows_b)
    {
        printf("First matrix cols - %i not matchign second matrix rows - %i", cols_a, rows_b);
        exit(1);
    }

    float **new_matrix = matrix(rows_a, cols_b);

    for (int i = 0; i < rows_a; i++)
        for (int j = 0; j < cols_b; j++)
            new_matrix[i][j] = 0;

    for (int i = 0; i < rows_a; i++)
    {
        for (int j = 0; j < cols_b; j++)
        {
            for (int p = 0; p < rows_a; p++)
                new_matrix[i][j] += matrix_a[i][j] * matrix_b[j][i];
        }
    }
    return new_matrix;
}
float **minor(int rows, int cols, int n, float **M);
float determinant(float **M, int cols)
{
    // if (rows != cols)
    // {
    //     printf("You should use square matrix rows - %i not matching to cols - %i", rows, cols);
    //     exit(1);
    // }

    if (cols == 2)
    {
        return (M[0][0] * M[1][1]) - (M[0][1] * M[1][0]);
    }
    float det;

    for (int i = 0; i < cols; i++)
    {
        float **m = minor(0, i, cols, M);
        printf("determinatn - %f, minor matrix size - %i, index - %i \n", det, cols, i);
        det += pow((-1), i) * M[0][i] * determinant(m, cols - 1);
        clear(cols, m);
    }
    return det;
}

float **minor(int rows, int cols, int size, float **M)
{
    int k = 0;
    int l = 0;
    // size = size - 1;
    float **m = matrix(size, size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != rows && j != cols)
            {
                m[k][l] = M[i][j];
                l++;
            }
        }
        if (i != rows)
            k++;
        l = 0;
    }
    return m;
}

int main()
{
    int rows_a = 5, cols_a = 5;
    int rows_b = 5, cols_b = 5;

    float **matrix_a = matrix(rows_a, cols_a);
    float **matrix_b = matrix(rows_b, cols_b);
    for (int i = 0; i < rows_a; i++)
    {
        for (int j = 0; j < cols_a; j++)
        {
            matrix_a[i][j] = rows_a * i + j + 1;
            printf("matrix_a %f ", matrix_a[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < rows_b; i++)
    {
        for (int j = 0; j < cols_b; j++)
        {
            matrix_b[i][j] = rows_b * i + j + 4;
        }
    }

    float **resoult = product(matrix_a, rows_a, cols_a, matrix_b, rows_b, cols_b);
    // for (int i = 0; i < rows_a; i++)
    // {
    //     for (int j = 0; j < cols_b; j++)
    //     {
    //         printf("%f ", resoult[i][j]);
    //     }
    //     printf("\n");
    // }
    float det = determinant(matrix_a, cols_a);
    printf("reosult determinant %f\n", det);
    clear(rows_a, matrix_a);
    clear(rows_b, matrix_b);
    clear(rows_a, resoult);

    return 0;
}
