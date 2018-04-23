#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv) {
	if (argc < 3) {
		fprintf(stderr, "Usage: ./first-fit no_of_processes no_of_blocks\n");
		exit(1);
	}
	int np = atoi(argv[1]);
	int nb = atoi(argv[2]);
	int processes[np], blocks[nb];
	char * process_blocks[nb];
	for (int i = 0; i < nb; ++i) {
		process_blocks[i] = (char *) malloc(sizeof(char) * (np + 1));	
		memset(process_blocks[i], '\0', sizeof(process_blocks[i]));
	}
	printf("Enter the memory requirements for the processes: \n");
	for (int i = 0; i < np; ++i) {
		printf("Process %d: ", i);
		scanf("%d", &processes[i]);
	}
	printf("Enter the memory allocated to blocks: \n");
	for (int i = 0; i < nb; ++i) {
		printf("Block %d: ", i);
		scanf("%d", &blocks[i]);
	}
	for (int i = 0; i < np; ++i) {
		int j;
		for (j = 0; j < nb; ++j) {
			int rem_space = blocks[j] - processes[i];
			if (rem_space >= 0) {
				break;
			}
		}	
		if (j != nb) {
			int k;
			for (k = 0; process_blocks[j][k] != '\0'; ++k); 
			process_blocks[j][k] = (char)(i + '0');
			blocks[j] -= processes[i];
		} else {
			printf("Process %d cannot be allocated a memory block!\n", i);	
		}
	}	
	printf("The processes have been allocated in the following way:\n");
	for (int i = 0; i < nb; ++i) {
		printf("Block[%d]: %s\n", i, process_blocks[i]);	
	}
	return 0;
}
