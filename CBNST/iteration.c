#include <stdio.h>
#include <math.h>

// Define the function you want to find the root for
double F(double x)
{
    return x * x * x - 4 * x - 9;
}

int main()
{
    double a, b;
    int maxIterations = 30;

    printf("Enter initial interval [a, b]: ");
    scanf("%lf %lf", &a, &b);

    double fa = F(a);
    double fb = F(b);

    if (fa * fb >= 0)
    {
        printf("Solution does not exist in the given interval.\n");
        return 1;
    }

    for (int iteration = 1; iteration <= maxIterations; iteration++)
    {
        double c = (a + b) / 2;
        double fc = F(c);

        printf("Iteration %d: x = %.4lf, f(x) = %.4lf\n", iteration, c, fc);

        if (fabs(fc) < 0.00005)
        { // Tolerance to 4 decimal places
            printf("Solution found after %d iterations.\n", iteration);
            printf("Approximate solution: %.4lf\n", c);
            return 0;
        }

        if (fa * fc < 0)
        {
            b = c;
            fb = fc;
        }
        else
        {
            a = c;
            fa = fc;
        }
    }

    printf("Maximum number of iterations reached.\n");
    return 0;
}
