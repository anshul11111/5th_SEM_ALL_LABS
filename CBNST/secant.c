#include <stdio.h>
#include <math.h>

#define F(x) (x * x * x - 4 * x - 9)

double SecantMethod(double x0, double x1, double tol)
{
    double x2, f0, f1;
    int itr = 0;

    do
    {
        f0 = F(x0);
        f1 = F(x1);
        x2 = x1 - (f1 * (x1 - x0) / (f1 - f0));
        printf("Iteration %d: x = %.4lf, f(x) = %.4lf\n", itr, x2, F(x2));

        if (fabs(x2 - x1) < tol)
        {
            printf("Converged to root: x = %.4lf\n", x2);
            return x2;
        }

        x0 = x1;
        x1 = x2;
        itr++;
    } while (itr < 100); // Maximum iterations to prevent infinite loop

    printf("Method did not converge\n");
    return NAN;
}

int main()
{
    double x0, x1, tol;

    printf("Enter initial guess x0: ");
    scanf("%lf", &x0);
    printf("Enter initial guess x1: ");
    scanf("%lf", &x1);
    printf("Enter tolerance: ");
    scanf("%lf", &tol);

    double root = SecantMethod(x0, x1, tol);
    printf("Root: %.4lf\n", root);

    return 0;
}
