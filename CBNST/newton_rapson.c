#include <stdio.h>
#include <math.h>

// Define the function F(x)
#define F(x) (x * x * x - 4 * x - 9)

// derivative of f(x) 
#define F_prime(x) (3 * x * x - 4)

// Newton-Raphson to find the root starts here
double NewtonRaphson(double x0)
{
    int maxIterations = 30;
    double epsilon = 0.0001; // Tolerance for convergence (precision)

    for (int itr = 0; itr < maxIterations; itr++)
    {
        double f_x0 = F(x0);
        double f_prime_x0 = F_prime(x0);

        // Check if the derivative is close to zero, which can lead to non-convergence
        if (fabs(f_prime_x0) < epsilon)
        {
            printf("Derivative is close to zero. The method may not converge.\n");
            return NAN;
        }

        double x1 = x0 - (f_x0 / f_prime_x0);

        // Check if the difference between successive roots is within the tolerance
        if (fabs(x1 - x0) < epsilon)
        {
            return x1;
        }

        x0 = x1; // Update the root 
    }

    printf("Method did not converge after %d iterations.\n", maxIterations);
    return NAN;
}

int main()
{
    double initialGuess = 1.0; // Set the initial guess for the root

    double root = NewtonRaphson(initialGuess);

    if (!isnan(root))
    {
        printf("Approximate Root: %.4lf\n", root);
    }
    else
    {
        printf("Unable to find a root within the specified tolerance.\n");
    }

    return 0;
}
