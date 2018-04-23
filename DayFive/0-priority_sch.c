#include <stdio.h>
//Smaller the number, higher the priority
typedef struct Process {
	int p_no;
	int arr_time;
	int start_time;
	int burst_time;
	int end_time;
	int priority;
}P;

void sort_processes(P[], int);

int main(void) {
	int n;
	printf("Enter the no of processes: ");
	scanf("%d", &n);
	printf("Enter the arrival times, burst times and priority of processes: \n");
	P p[n];
	for (int i = 0; i < n; ++i) {
		printf("P[%d]: ", i);
		scanf("%d %d %d", &p[i].arr_time, &p[i].burst_time, &p[i].priority);
		p[i].p_no = i;
		p[i].start_time = -1;
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
	int burst_times[n];
	for (int i = 0; i < n; ++i) {
		burst_times[i] = p[i].burst_time;	
	}
	int cur_time = 0, cur_priority = 999, cur_process = -1, done = 0, flag_changed = 0;
	while (done < n) {
		for (int i = 0; i < n; ++i) {
			if (cur_time >= p[i].arr_time && p[i].burst_time != 0) {
				if (p[i].priority < cur_priority) {
					cur_priority = p[i].priority;
					cur_process = i;
					flag_changed = 1;
				}
			}
		}	
		if (flag_changed) {
			if (p[cur_process].start_time == -1) {
				p[cur_process].start_time = cur_time;	
				flag_changed = 0;
			}	
		}
		if (cur_priority != 999) {
			p[cur_process].burst_time -= 1;
			printf("P%d ", p[cur_process].p_no);
			if (p[cur_process].burst_time == 0) {
				done++;		
				cur_priority = 999;
				p[cur_process].end_time = cur_time;
			}
		}
		cur_time++;	
	}
	printf("\n");
	int total_wait_time = 0;
	for (int i = 0; i < n; ++i) {
		int turnaround_time = p[i].end_time - p[i].arr_time + 1; 
		int wait_time = turnaround_time - burst_times[i];
		total_wait_time += wait_time;
		printf("Waiting time for p[%d] is: %d\n", p[i].p_no, wait_time);
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
