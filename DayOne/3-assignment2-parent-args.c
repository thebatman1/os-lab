#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char ** argv) {
	if (argc < 3) {
		fprintf(stderr, "Usage: ./a.out path_of_child child");	
		exit(1);
	}
	pid_t return_val;
	int status;
	return_val = fork();
	if (return_val > 0) {
		wait(&status);
		printf("Child terminated\n");
	}
	else if (return_val == 0) {
		printf("Child starts\n");
		if (execl(argv[1], argv[2], NULL) < 0) {
			fprintf(stderr, "Error : %s\n", strerror(errno));	
			exit(1);
		}
	}
	else {
		fprintf(stderr, "Process creation unsuccessful\n");
	}
	return 0;
}
