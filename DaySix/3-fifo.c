#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv) {
	if (argc < 3) {
		fprintf(stderr, "Usage: ./fifo no_of_processes no_of_blocks\n");
		exit(1);
	}
	int np = atoi(argv[1]);
	int nb = atoi(argv[2]);
	char * processes = (char *) malloc (sizeof(char) * (np + 1));
	char * blocks = (char *) malloc (sizeof(char) * (nb + 1));
	int last_used[nb];
	int present_index[10] = {-1};
	memset(present_index, -1, sizeof(present_index));
	memset(last_used, -1, sizeof(last_used));
	memset(blocks, '\0', sizeof(blocks));
	printf("Enter the process string: ");
	scanf("%s", processes);
	printf("%s\n", processes);
	int page_faults = 0;
	for (int i = 0; processes[i] != '\0'; ++i) {
		int index, j, min = 10000, min_index = -1;
		if ((index = present_index[(int)(processes[i] - '0')]) == -1) {
			page_faults++;
			for (j = 0; j < nb; ++j) {
				if (last_used[j] == -1) {
					blocks[j] = processes[i];
					last_used[j] = i;
					present_index[(int)(processes[i] - '0')] = j;
					min_index = -1;
					break;
				} else if (last_used[j] < min) {	
					min = last_used[j];
					min_index = j;
				}		
			}			
			if (min_index != -1) {
				present_index[(int)(blocks[min_index] - '0')] = -1;
				blocks[min_index] = processes[i];
				last_used[min_index] = i;
				present_index[(int)(processes[i] - '0')] = min_index;
			}
		}
		printf("%c %s\n", processes[i], blocks);
	}	
	printf("No of page faults: %d\n", page_faults);
	return 0;
}
