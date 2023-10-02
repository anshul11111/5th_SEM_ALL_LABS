#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define SIZE 100

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int at[], int bt[], int n)
{
    int i, j;
    bool swapped;

    for (i = 0; i < n - 1; i++)
    {
        swapped = false;

        for (j = 0; j < n - i - 1; j++)
        {
            if (at[j] > at[j + 1])
            {
                swap(&at[j], &at[j + 1]);
                swap(&bt[j], &bt[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

int main()
{
    int at[SIZE], bt[SIZE], n;

    printf("Enter the number of processes:\n");
    scanf("%d", &n);

    int rbt[SIZE];

    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time of process %d:\n", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time of process %d:\n", i + 1);
        scanf("%d", &bt[i]);
    }
    bubbleSort(at, bt, n);

    for (int i = 0; i < n; i++)
    {
        rbt[i] = bt[i];
    }

    int cpt = 0;
    int ct[SIZE];
    int tat[SIZE];
    int wt[SIZE];
    int counter = 0;
    int min = INT_MAX;
    int check = 0;

    while (counter != n)
    {
        for (int i = 0; i < n; i++)
        {
            if (rbt[i] > 0 && rbt[i] < min && at[i] <= cpt)
            {
                min = rbt[i];
                check = i;
            }
        }
        rbt[check]--;
        cpt++;
        min = rbt[check];
        if (min == 0)
        {
            min = INT_MAX;
            ct[check] = cpt;
            counter++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (wt[i] < 0)
        {
            wt[i] = 0;
        }
        tat[i] = ct[i] - at[i];
        if (tat[i] < 0)
        {
            tat[i] = 0;
        }
    }

    printf("At\t\tBt\t\tCt\t\tWt\t\tTat\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", at[i], bt[i], ct[i], wt[i], tat[i]);
    }
    return 0;
}
