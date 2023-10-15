#include <stdio.h>
#include <math.h>

#define F(x) (x * x * x - 4 * x - 9)

int FindRoot(double x0, double x1, double *root)
{
    if (F(x0) * F(x1) >= 0)
        return -1;
    int itr = 0;
    double x2, prev_x2;
    prev_x2 = x1;
    printf("| Iteration |    x     |    x0    |    x1    |\n");
    printf("-------------------------------------------\n");
    do
    {
        x2 = (x0 + x1) / 2;
        itr++;
        printf("|    %4d   | %.4lf | %.4lf | %.4lf |\n", itr, x2, x0, x1);
        if (F(x0) * F(x2) < 0)
            x1 = x2;
        else if (F(x2) * F(x1) < 0)
            x0 = x2;
        if (fabs(x2 - prev_x2) <= 0.0001)
            break;
        prev_x2 = x2;
    } while (1);
    *root = x2;
    return itr;
}

int main()
{
    double x0, x1, root;
    printf("Enter Interval (x0, x1): ");
    scanf("%lf %lf", &x0, &x1);
    int itr = FindRoot(x0, x1, &root);
    if (itr == -1)
    {
        printf("Invalid Interval\n");
        return 1;
    }
    printf("-----------------------------------------\n");
    printf("Root: %.4lf\n", root);
    printf("Iterations: %d\n", itr);
    printf("-----------------------------------------\n");
    return 0;
}
