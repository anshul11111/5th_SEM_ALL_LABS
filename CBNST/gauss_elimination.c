#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    double A[n][n + 1], X[n];

    printf("Enter the coefficients of the equations and right-hand side values:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }

    // Gauss Elimination
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double factor = A[j][i] / A[i][i];
            for (int k = i; k <= n; k++)
            {
                A[j][k] -= factor * A[i][k];
            }
        }
    }

    // Back-substitution
    for (int i = n - 1; i >= 0; i--)
    {
        X[i] = A[i][n];
        for (int j = i + 1; j < n; j++)
        {
            X[i] -= A[i][j] * X[j];
        }
        X[i] /= A[i][i];
    }

    
    printf("Solution:\n");
    for (int i = 0; i < n; i++)
    {
        printf("X[%d] = %.4lf\n", i, X[i]);
    }

    return 0;
}
