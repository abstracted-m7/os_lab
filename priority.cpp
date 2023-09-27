#include<stdio.h>
#define max 30
int main(){
	int p,pid[max],temp,bt[max],pr[max],i,j,wt[max],tat[max];
	float awt,atat;
	float throu=0;
	printf("Enter the number of process: ");
	scanf("%d",&p);

    // From ueser --> burst time in process id
	printf("Enter the number of BT :\n");
	for(i=0;i<p;i++){
		scanf("%d",&bt[i]);
		pid[i]=i+1;

	}
	printf("Enter the number of priority :\n");
	// from user priority value
	for(i=0;i<p;i++){
		scanf("%d",&pr[i]);
	}
	//display Question
	//printf("pid \t burst_time \t priority\n");
	//for(i=0;i<p;i++){
	//	printf("%d \t %d \t %d\n",pid[i],bt[i],pr[i]);
		
	//}
    // sorting the size of burst time
	for(i=0;i<p;i++){
		for(j=0;j<p-i-1;j++){
			if(pr[j]>pr[j+1])
			{
				temp=pr[j+1];
				pr[j+1]=pr[j];
				pr[j]=temp;
				
				
				temp=bt[j+1];
				bt[j+1]=bt[j];
				bt[j]=temp;
				
				temp=pid[j+1];
				pid[j+1]=pid[j];
				pid[j]=temp;
			}
		}
	}
	
	printf("process \t priority\t burst_time \tTAT \t Waiting_Time\n");
    // Calculating the wt & tat time
	for(i=0;i<p;i++){
		wt[i]=0;
		tat[i]=0;
		
		for(j=0;j<i;j++){	
			wt[i]=wt[i]+bt[j];
		}
		tat[i]=wt[i]+bt[i];

        // print that
		printf("P[%d] \t\t %d \t\t %d \t\t %d \t\t %d\n",pid[i],pr[i],bt[i],tat[i],wt[i]);

        // calculating the avarage times
		awt=awt+wt[i];
		atat=atat+tat[i];
		}
		awt=awt/p;
		atat=atat/p;
		printf("Average wt is: %.2f\n",awt);
		printf("Average tat is: %.2f\n",atat);
		
        // calculate & print the throughput
		for(i=0;i<p;i++){
			throu=throu+bt[i];
		}
		printf("Through_put is: %.2f",p/throu);
        return 0;
}
