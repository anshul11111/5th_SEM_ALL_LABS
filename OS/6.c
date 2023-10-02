#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int artotal(int a[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += a[i];
    }
    return res;
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
    int ct[SIZE];
    int tat[SIZE];
    int wt[SIZE];

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
        ct[i] = 0;
        tat[i] = 0;
        wt[i] = 0;
    }

    int cpt = 0;
    int i = 0;

    while (1)
    {
        bool done = true;
        for (int j = 0; j < n; j++)
        {
            if (rbt[j] > 0)
            {
                done = false;
                if (rbt[j] > 2)
                {
                    cpt += 2;
                    rbt[j] -= 2;
                }
                else
                {
                    cpt += rbt[j];
                    rbt[j] = 0;
                    ct[j] = cpt;
                    tat[j] = ct[j] - at[j];
                    wt[j] = tat[j] - bt[j];
                }
            }
        }
        if (done)
            break;
    }

    printf("At\t\tBt\t\tCt\t\tWt\t\tTat\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", at[i], bt[i], ct[i], wt[i], tat[i]);
    }
    return 0;
}
