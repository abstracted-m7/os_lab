#include<stdio.h>
#define max 30
int main(){
	int p,k=1,bt[max],wt[max],tat[max],i,j,p1[max];
	float awt,atat;
	float throu=0;
	printf("Enter the number of process: ");
	scanf("%d",&p);

    // From ueser --> burst time in process id
	for(i=0;i<p;i++){
		printf("Enter burst time of p[%d]: ",k);
		p1[i]=k;
		scanf("%d",&bt[i]);
		k++;
	}
	
    // sorting the size of burst time
	for(i=0;i<p-1;i++){
		for(j=0;j<p-1;j++){
			if(bt[j]>bt[j+1]){
				int temp;
				temp=bt[j+1];
				bt[j+1]=bt[j];
				bt[j]=temp;
                // Exchange the process id besis on Burst time
				int temp1;
				temp1=p1[j+1];
				p1[j+1]=p1[j];
				p1[j]=temp1;
				
				
			}
		}
	}
	printf("process \t burst_time \t waiting_time \t TAT\n");
    // Calculating the wt & tat time
	for(i=0;i<p;i++){
		wt[i]=0;
		tat[i]=0;
		
		for(j=0;j<i;j++){	
			wt[i]=wt[i]+bt[j];
		}
		tat[i]=wt[i]+bt[i];

        // print that
		printf("P[%d] \t\t %d \t\t %d \t\t %d\n",p1[i],bt[i],wt[i],tat[i]);

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
		printf("Through_put is: %.2f",throu/p);
        return 0;
}