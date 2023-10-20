#include <stdio.h>
#define INT_MAX 1e9
struct process
{
    int pid;
    int priority;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
    int start_time;
};
int main()
{
    struct process p[100];
    int n;
    printf("enter the no of processes:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i;
        printf("enter the arrival time,burst time and priority for process %d :->\n", i);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].priority);
    }
    int iscompleted[n];
    for (int i = 0; i < n; i++)
    {
        iscompleted[i] = 0;
    }
    int completed = 0;
    int current_time = 0;
    int ideal_time = 0;
    while (completed != n)
    {
        int max_index = -1;
        int maxi = -1;
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= current_time && iscompleted[i] == 0)
            {
                if (p[i].priority > maxi)
                {
                    maxi = p[i].priority;
                    max_index = i;
                }
                else if (p[i].priority == maxi)
                {
                    if (p[i].at < p[max_index].at)
                    {
                        maxi = p[i].priority;
                        max_index = i;
                    }
                }
            }
        }
        if (max_index != -1)
        {
            p[max_index].start_time = current_time;
            p[max_index].ct = p[max_index].start_time + p[max_index].bt;
            p[max_index].tat = p[max_index].ct - p[max_index].at;
            p[max_index].wt = p[max_index].tat - p[max_index].bt;
            p[max_index].rt = p[max_index].start_time - p[max_index].at;
            completed++;
            current_time = p[max_index].ct;
            iscompleted[max_index] = 1;
        }
        else
        {
            ideal_time++;
            current_time++;
        }
    }
    printf("PID\tPr\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].priority, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt, p[i].rt);
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
