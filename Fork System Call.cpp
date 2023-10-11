#include<stdio.h>
#include<unistd.h>
int main(){
	int pid,a,b,c;
	printf("Enter the first value : ");
	scanf("%d",&a);
	printf("\n\nEnter the second value : ");
	scanf("%d",&b);
	pid=fork();
	printf("The pid is : %d\n",pid);
	if(pid<0){
		printf("Process not created.\n");
	}
	else if(pid>0){
		printf("Hi i'm in parent process.\n\n");
		c=a+b;
		printf("The sum of two number is : %d\n\n",c);

	}
	else{
		printf("Hi i'm child process\n");
		c=a-b;
		printf("The substraction of two number is : %d\n\n",c);
	}
	return 0;
}
