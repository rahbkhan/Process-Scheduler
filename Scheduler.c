/*
 ============================================================================
 Name        : Process Scheduler
 Author      : Robert H Conner II
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct process{
	int id;
	int arrival_time;
	int priority;
	float cpu_burst;

};

//Sort
int struct_cmp_by_price(const void *a, const void *b)
{
    struct process *ia = (struct process *)a;
    struct process *ib = (struct process *)b;
    return (int)(100.f*ia->arrival_time - 100.f*ib->arrival_time);


}

int main() {

	struct process processes [50];
	int i;

	for(i=0; i<50; i++){
		processes[i].id= i + 1;
		processes[i].arrival_time= rand() %20;
		processes[i].priority= rand() %10;
		processes[i].cpu_burst= random()%15+1;

	}
printf("Process ID | Arrival Time |     Priority      | CPU Burst\n");

	for(i=0; i<50; i++){
		printf("%d\t\t", processes[i].id);
		printf("%d\t\t", processes[i].arrival_time);
		printf("%d\t\t", processes[i].priority);
		printf("%3.2f\t\t", processes[i].cpu_burst);
		printf("\n");
	}

	qsort(processes, 50, sizeof(struct process), struct_cmp_by_price);

	printf("\nAfter sorting the list is according to arrival time: \n\n");
	   for( i = 0 ; i < 50; i++ ) {
		   	   	printf("%d\t\t", processes[i].id);
		   		printf("%d\t\t", processes[i].arrival_time);
		   		printf("%d\t\t", processes[i].priority);
		   		printf("%3.2f\t\t", processes[i].cpu_burst);
		   		printf("\n");
	   }
	   int n=50;
	   int t[50],w[50],g[50];
	   g[0]=0;
	   float att=0,awt=0;

	   for(i=0;i<n;i++)
	    g[i+1]=g[i]+ processes[i].cpu_burst;
	    for(i=0;i<n;i++)
	    {
	     w[i]=g[i]-processes[i].arrival_time;
	     t[i]=g[i+1]-processes[i].arrival_time;
	     awt=awt+w[i];
	     att=att+t[i];
	    }
	    awt =awt/n;
	    att=att/n;

	    printf("the average waiting time is :%3.2f\n",awt);
	    printf("the average turn around time is :%3.2f\n",att);

	    return 0;

}

