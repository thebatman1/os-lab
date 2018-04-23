#include <stdio.h>
#define TIME_SLICE 2
#define MAX 1000

typedef struct process {
	int p_no;
	int arr_time;
	int burst_time;
	int start_time;
	int end_time;
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

	int cur_time = 0, i = 0, done = 0, count_wait = 0;
	int burst_time[n];
	for (int l = 0; l < n; ++l) {
		burst_time[l] = p[l].burst_time;	
	}
	while (done < n) {
		if (count_wait == n - done) {
			count_wait = 0;
			cur_time += 1;
		}
		if (cur_time >= p[i].arr_time && p[i].burst_time > 0) {
			count_wait = 0;
			if (p[i].burst_time >= TIME_SLICE) {
				p[i].burst_time -= TIME_SLICE;	
				cur_time += TIME_SLICE;	
				if (p[i].burst_time == 0) {
					p[i].end_time = cur_time;
					printf("%d\n", cur_time);
					done++;	
				}
			} else if (p[i].burst_time > 0 && p[i].burst_time < TIME_SLICE) {
				cur_time += p[i].burst_time;
				p[i].burst_time = 0;
				p[i].end_time = cur_time;
				printf("%d\n", cur_time);
				done++;
			}		
		} else if (p[i].burst_time != 0) {
			count_wait++;
		}
		i = (i + 1) % n;
	}



	printf("\n");
	int total_wait_time = 0;
	for (int i = 0; i < n; ++i) {
		int turnaround_time = p[i].end_time - p[i].arr_time;
		int wait_time = p[i].end_time - burst_time[i];
		total_wait_time += wait_time;
		printf("Waiting time for p[%d] is: %d\n", p[i].p_no, (wait_time > 0) ? (wait_time) : 0); 
		printf("Completion time for p[%d] is: %d\n", p[i].p_no, p[i].end_time);
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
