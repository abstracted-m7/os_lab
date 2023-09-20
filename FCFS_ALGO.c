#include<stdio.h>
#define max 30
int main()
{
    int n,i,j,bt[max],wt[max],tat[max];
    float awt,atat;
    printf("Enter the number of process : ");
    scanf("%d",&n);
    printf("Enter the burst time of %d : ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    printf("Process_Id\tBurst_Time\tWaiting_Time\tTA_Time\n");
    for(i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
        for(j=0;j<i;j++)
        {
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
        awt=awt+wt[i];
        atat=atat+tat[i];
    }
    awt=awt/n;
    printf("Avg of Waiting_Time : %.2f \n",awt);
    atat=atat/n;
    printf("Avg of TAT : %.2f",atat);
    return 0;
}
