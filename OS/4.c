#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

// Swap function to swap two integers
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Bubble sort function to sort processes by arrival time
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

    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time of process %d:\n", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time of process %d:\n", i + 1);
        scanf("%d", &bt[i]);
    }

    bubbleSort(at, bt, n);

    int ct[SIZE];
    int tat[SIZE];
    int wt[SIZE];
    int i1 = 0;

    while (true)
    {
        if (i1 == 0)
        {
            ct[i1] = at[i1] + bt[i1];
            tat[i1] = ct[i1] - at[i1];
            wt[i1] = 0;
        }
        else
        {
            ct[i1] = ct[i1 - 1] + bt[i1];
            tat[i1] = ct[i1] - at[i1];
            wt[i1] = tat[i1] - bt[i1];
        }
        i1++;
        if (i1 == n)
            break;
    }

    printf("At\t\tBt\t\tCt\t\tWt\t\tTat\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    return 0;
}
