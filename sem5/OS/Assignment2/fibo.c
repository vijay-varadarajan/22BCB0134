#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
// 11/03/2020 OPERATING_SYSTEMS_HW 06:38:24
// Printing Fibonacci with fork()

int main(){

	int pid,fd[2],n;
	int sum=0;
	int t1 = 0, t2 = 1, nextTerm;
	int son=0;

	if(pipe(fd)==-1)
	{
		printf("\nError in pipe connection\n");
		return 0;
	}

	pid=fork();

	if(pid>0)
		{ //PARENT
		printf("Enter the number of elements: \n");
		scanf("%d",&n); 

		//close(fd[0]);
		write(fd[1],&n,sizeof(n)); 
		close(fd[1]); 

		wait(NULL); 
		read(fd[0],&son,sizeof(son)); 
		printf("F(n): %d",son);

		read(fd[0],&sum,sizeof(sum));
		printf("   SUM: %d\n",sum);

		exit(0);

	}

	else{ //CHILD

		read(fd[0],&n,sizeof(n)); 
		close(fd[0]); 

		printf("\n"); 
		//FIBONACCI LOOP
		printf("Fibonacci Series:  ");
		for (int i = 1; i <= n; ++i) {
					
			nextTerm = t1 + t2;
			t1 = t2;
			t2 = nextTerm;
			printf("%d ", t1);
			son=t1;
			sum+=t1;
		}
		
		printf("\n");		
	
		write(fd[1],&son,sizeof(son));
		write(fd[1],&sum,sizeof(sum));

	}

}