#include <stdio.h>
#include <math.h>

#define F(x) (x * x * x - 4 * x - 9)
#define Fu "f(x) = x^2 - 4x - 9 = 0"
#define SECANT(x0, x1) (x1 - ((x1 - x0) / (F(x1) - F(x0))) * F(x1))

int FindRoot(double x0, double x1, double *root)
{
    int itr = 0;
    double x2, prev_x2;
    prev_x2 = x1; // Initialize previous root value with x1 for Secant

    do
    {
        x2 = SECANT(x0, x1);
        itr++; // Increment the iteration count
        printf("Iteration: %d value: %.4lf; For x0: %.4lf x1: %.4lf\n", itr, x2, x0, x1);

        if (fabs(x2 - prev_x2) <= 0.0001)
            break; // stop on: |x(n) - x(n-1)| <= 0.0001

        prev_x2 = x2; // Update previous root value
        x0 = x1;      // Update x0 with the current value of x1
        x1 = x2;      // Update x1 with the current value of x2
    } while (1);

    *root = x2;
    return itr;
}

int main()
{
    int ch;
    double x0, x1, root; // Set precision to 4 decimal places
    printf("Enter Interval (x0, x1): ");
    scanf("%lf %lf", &x0, &x1);
    printf("\t\tSecant Method\n");
    int itr = FindRoot(x0, x1, &root); // Pass root by reference
    printf("Root of Function %s: %.4lf\n", Fu, root);
    printf("After: %d Iterations\n", itr);
    return 0;
}
