#include <stdio.h>
struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
    int start_time;
    int bt_rem;
};

int max(int a, int b)
{
    if (a < b)
    {
        return b;
    }
    return a;
}

void sort(struct process *p, int n)
{
    struct process temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int n;
    printf("enter the number of processes:\n");
    scanf("%d", &n);
    struct process p[n];
    int visited[100] = {0};
    int tq;
    for (int i = 0; i < n; i++)
    {
        printf("enter the arrival time and burst time:\n");
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].pid = i;
        p[i].bt_rem = p[i].bt;
    }
    printf("enter time quant :\n");
    scanf("%d", &tq);
    int completed = 0;
    int current_time = 0;
    sort(p, n);
    int index = 0;
    int queue[100], front = 0, rear = 0;
    queue[rear] = 0;
    int ideal_time = 0;
    visited[0] = 1;
    while (completed != n)
    {
        index = queue[front];
        front++;
        if (p[index].bt_rem == p[index].bt)
        {
            p[index].start_time = max(current_time, p[index].at);
            ideal_time += p[index].start_time - current_time;
            current_time = p[index].start_time;
        }
        if (p[index].bt_rem > tq)
        {
            p[index].bt_rem -= tq;
            current_time += tq;
        }
        else
        {
            current_time += p[index].bt_rem;
            p[index].bt_rem = 0;
            completed++;
            p[index].ct = current_time;
            p[index].tat = p[index].ct - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            p[index].rt = p[index].start_time - p[index].at;
        }
        for (int i = 1; i < n; i++)
        {
            if (p[i].bt_rem > 0 && p[i].at <= current_time && visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
        if (p[index].bt_rem > 0)
        {
            queue[++rear] = index;
        }
        if (front > rear)
        {
            for (int i = 1; i < n; i++)
            {
                if (p[i].bt > 0)
                {
                    queue[++rear] = i;
                    visited[i] = 1;
                    break;
                }
            }
        }
    }
    printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt, p[i].rt);
    }
    int max_ct = -1;
    float sum_tat = 0;
    float sum_wt = 0;
    float avg_tat = 0;
    float avg_wt = 0;
    for (int i = 0; i < n; i++)
    {
        if (max_ct < p[i].ct)
        {
            max_ct = p[i].ct;
        }
        sum_tat += p[i].tat;
        sum_wt += p[i].wt;
    }
    avg_tat = sum_tat / (float)n;
    avg_wt = sum_wt / (float)n;
    float throughput = (float)n / (float)max_ct;
    float cpu_utz = (float)(max_ct - ideal_time) * 100 / (float)max_ct;
    printf("\nideal time is %f \n", ((float)ideal_time / (float)max_ct) * 100);
    printf("cpu utilization time is %f \n", cpu_utz);
    printf("average tat %f \n", avg_tat);
    printf("average wt %f \n", avg_wt);
    printf("throughout is %f ", throughput);
    return 0;
}