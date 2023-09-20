#include<stdio.h>
#define max 30
int main(){
	int n,y,k=1,m=1,at[max],bt[max],i,j,p1[max],qt,temp[max],count=1,ct;
	float awt,atat;
	float throu=0;
	printf("Enter the number of process: ");
	scanf("%d",&n);
    y=n;

    // From ueser --> burst time in process id
	for(i=0;i<n;i++){
		printf("\nEnter burst time of p[%d]: ",k);
		p1[i]=k;
		scanf("%d",&bt[i]);
		k++; // k denoted by increment of processes
        temp[i]=bt[i];
        // printf("The temp value : %d \n",temp[i]);
	}
    // From user --> Arrivel time
    for(i=0;i<n;i++){
        printf("\nEnter arrivel time of p[%d] :",m);
        p1[i]=m; // m denoted for increment of processes
        scanf("%d",&at[i]);
        m++;
        // printf("\nThe arrivel time is : %d",at[i]);
    }
    
    // For quantum time --->
    printf("\nEnter the quantum time : ");
    scanf("%d",&qt);

    printf("\nP_ID\tA_T\tB_T\tC_T\tTAT\tW_T");

    //Calculation part
    for(i=0,ct=0;y>0;){
        if(temp[i]<=qt && temp[i]>0)
        {
            ct=ct+temp[i];
            temp[i]=0;
            count=1;
        }
        else if (temp[i]>0)
        {
            temp[i]=temp[i]-qt;
            ct=ct+qt;
        }
        if (temp[i]==0 && count==1)
        {
            y--; // decrise (updation)
            printf("\np[%d]\t%d\t%d\t%d\t%d\t%d",(i+1),at[i],bt[i],ct,ct-at[i],(ct-at[i])-bt[i]);

            // claculating the average of wt and tat
            awt=awt+ct-at[i]-bt[i];
            atat=atat+ct-at[i];
            count=0;
        }
        if (i==n-1)
        {
            i=0;
        }
        else if (at[i+1]<=ct)
        {
            i++;
        }
        else
        {
            i=0;
        }
    }


    // Avg time of wt and tat
    awt=awt/n;
	atat=atat/n;
	printf("\nAverage wt is: %.2f",awt);
	printf("\nAverage tat is: %.2f",atat);
    // calculate & print the throughput
	for(i=0;i<n;i++){
		throu=throu+bt[i];
	}
	printf("\nThrough_put is: %.2f",throu/n);
    return 0;
}