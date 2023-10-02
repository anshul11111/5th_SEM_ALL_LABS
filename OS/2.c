#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 100

int main()
{
    pid_t p;
    int i;
    int n, sum_even = 0, sum_odd = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[MAX];

    printf("Enter values into the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    p = fork();

    if (p == 0)
    {
        // Child process computes the sum of even numbers
        for (i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
            {
                sum_even += arr[i];
            }
        }
        printf("Sum of even numbers in the array: %d\n", sum_even);
        exit(0);
    }
    else if (p > 0)
    {
        // Parent process computes the sum of odd numbers
        for (i = 0; i < n; i++)
        {
            if (arr[i] % 2 != 0)
            {
                sum_odd += arr[i];
            }
        }
        printf("Sum of odd numbers in the array: %d\n", sum_odd);
        exit(0);
    }
    else
    {
        // Error occurred
        fprintf(stderr, "Fork failed\n");
        return 1;
    }

    return 0;
}
