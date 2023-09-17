#include <stdio.h>
#include <math.h>

double equation(double x)
{
    return x * x * x - 4 * x - 9; // can change the equation later
}

void bisection(double a, double b, int maxIterations)
{
    if (equation(a) * equation(b) >= 0)
    {
        printf("Invalid initial interval\n");
        return;
    }

    double c;
    int iteration = 0;

    printf("Iteration\t Letf interval\t Right interval\t Average\t f(x)\n");
    printf("___________________________\n");

    do
    {
        c = (a + b) / 2;

        printf("%8d\t%10lf\t%10lf\t%10lf\t%10lf\n", iteration, a, b, c, equation(c));

        if (equation(c) == 0.0)
            break;

        if (equation(c) * equation(a) < 0)
            b = c;
        else
            a = c;

        iteration++;
    } while (iteration <= maxIterations && fabs(b - a) > 1e-10);

    printf("___________________________\n");

    printf("Root:%d \nNumber of iterations: %lf\n", iteration, c);
}

int main()
{
    double a, b;
    int maxIterations;

    printf("Enter the left endpoint of the interval: ");
    scanf("%lf", &a);

    printf("Enter the right endpoint of the interval: ");
    scanf("%lf", &b);

    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxIterations);

    bisection(a, b, maxIterations);

    return 0;
}
