#include <stdio.h>
#include <string.h>

int main()
{
    int n, q;
    
    printf("");
    scanf("%d", &n);

    char pid[n][10];
    int at[n], bt[n], rt[n];
    int wt[n], tat[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%s %d %d", pid[i], &at[i], &bt[i]);
        rt[i] = bt[i]; 
    }

    scanf("%d", &q);

    int time = 0, completed = 0;

    while(completed < n)
    {
        int done = 1;

        for(int i = 0; i < n; i++)
        {
            if(rt[i] > 0 && at[i] <= time)
            {
                done = 0;

                if(rt[i] > q)
                {
                    time += q;
                    rt[i] -= q;
                }
                else
                {
                    time += rt[i];
                    wt[i] = time - bt[i] - at[i];
                    rt[i] = 0;
                    completed++;
                }
            }
        }

        if(done)
            time++;
    }

    float avg_wt = 0, avg_tat = 0;

    printf("Waiting Time:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%s %d\n", pid[i], wt[i]);
        avg_wt += wt[i];
    }

    printf("Turnaround Time:\n");
    for(int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        printf("%s %d\n", pid[i], tat[i]);
        avg_tat += tat[i];
    }

    printf("Average Waiting Time: %.2f\n", avg_wt / n);
    printf("Average Turnaround Time: %.2f\n", avg_tat / n);

    return 0;
}
