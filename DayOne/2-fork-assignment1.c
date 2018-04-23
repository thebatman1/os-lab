#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void) {
	pid_t return_val;
	int x = 100;
	return_val = fork();
	if (return_val > 0) {
		printf("Parent process\n");
		printf("Process id: %d\n", getpid());
		printf("x = %d\n", x);
		printf("Process id of shell: %d\n", getppid());
	}
	else if (return_val == 0) {
		printf("Child process\n");
		printf("Process id: %d\n", getpid());
		printf("x = %d\n", x);
		printf("Process id of parent: %d\n", getppid());
	}
	else {
		fprintf(stderr, "Process creation unsuccessful\n");
		exit(1);
	}
	return 0;
}
