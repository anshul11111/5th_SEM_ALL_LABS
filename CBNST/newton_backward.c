#include <stdio.h>

// Calculation of u mentioned in the formula
float u_cal(float u, int n)
{
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u + i);
    return temp;
}

// Calculating factorial of given n
int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

int main()
{
    // number of values given
    int n = 5;
    float x[] = {1891, 1901, 1911, 1921, 1931};

    // y[][] is used for the difference table and y[][0] used for input
    float y[n][n];
    y[0][0] = 46;
    y[1][0] = 66;
    y[2][0] = 81;
    y[3][0] = 93;
    y[4][0] = 101;

    // Calculating the backward difference table
    for (int i = 1; i < n; i++)
    {
        for (int j = n - 1; j >= i; j--)
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
    }

    // Displaying the backward difference table
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            printf("%4.2f\t", y[i][j]);
        printf("\n");
    }

    // Value to interpolate at
    float value = 1925;

    // Initializing u and sum
    float sum = y[n - 1][0];
    float u = (value - x[n - 1]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++)
    {
        sum = sum + (u_cal(u, i) * y[n - 1][i]) / fact(i);
    }

    printf("\nValue at %.2f is %.4f\n", value, sum);
    return 0;
}