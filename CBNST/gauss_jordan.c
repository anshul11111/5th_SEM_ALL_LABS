#include <stdio.h>

void printMatrix(double mat[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.4lf\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;

    printf("Enter the number of equations: ");
    scanf("%d", &n);

    double matrix[100][100], result[100];

    printf("Enter the coefficients of the equations:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &matrix[i][j]);
        }
    }

    // Perform Gauss-Jordan elimination
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                double ratio = matrix[j][i] / matrix[i][i];
                for (int k = 0; k < n; k++)
                {
                    matrix[j][k] -= ratio * matrix[i][k];
                }
            }
        }
    }

    // Normalize the rows
    for (int i = 0; i < n; i++)
    {
        double divisor = matrix[i][i];
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] /= divisor;
        }
    }

    // Extract the solution
    for (int i = 0; i < n; i++)
    {
        result[i] = matrix[i][n];
    }

    printf("Solution:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x%d = %.4lf\n", i + 1, result[i]);
    }

    return 0;
}
