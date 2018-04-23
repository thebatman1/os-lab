#include <stdio.h>

typedef struct process {
	int p_no;
	int arr_time;
	int burst_time;
	int start_time;
}P;
void sort_processes(P[], int n);

int main(void) {
	int n;
	printf("Enter the no of processes: ");
	scanf("%d", &n);
	printf("Enter the arrival times and burst times of processes: \n");
	P p[n];
	for (int i = 0; i < n; ++i) {
		printf("P[%d]: ", i);
		scanf("%d %d", &p[i].arr_time, &p[i].burst_time);
		p[i].p_no = i;
		p[i].start_time = p[i].arr_time;
	} 
	for (int i = 0; i < n; ++i) {
		printf("P[%d]\t%d\t%d\n", p[i].p_no, p[i].arr_time, p[i].burst_time);	
	}
	sort_processes(p, n);
	printf("After sorting:\n");
	for (int i = 0; i < n; ++i) {
		printf("P[%d]\t%d\t%d\n", p[i].p_no, p[i].arr_time, p[i].burst_time);	
	}
	printf("\n");
	for (int i = 1; i < n; ++i) {
		int prev_time = p[i-1].start_time + p[i-1].burst_time;
		p[i].start_time = (prev_time > p[i].arr_time)?prev_time:p[i].arr_time;		
	}
	printf("\n");
	int total_wait_time = 0;
	for (int i = 0; i < n; ++i) {
		int wait_time = p[i].start_time - p[i].arr_time;
		total_wait_time += wait_time;
		printf("Waiting time for p[%d] is: %d\n", p[i].p_no, (wait_time > 0) ? (wait_time) : 0);
		int completion_time = p[i].start_time + p[i].burst_time;
		printf("Completion time for p[%d] is: %d\n", p[i].p_no, completion_time);
		int turnaround_time = completion_time - p[i].arr_time;
		printf("Turnaround time for p[%d] is: %d\n", p[i].p_no, turnaround_time);
		printf("\n");
	}
	printf("Average waiting time: %d/%d or %lf\n", total_wait_time, n, total_wait_time/(double)n);
	return 0;	
}

void sort_processes(P p[], int n) {
	for ( int i = 1; i < n; ++i) {
		P x = p[i];
		int j = i - 1;
		while ( j >=0 && p[j].arr_time > x.arr_time) {
			p[j + 1] = p[j];	
			j--;
		}
		if (i != j) {
			p[j + 1] = x;	
		}	
	} 
}
