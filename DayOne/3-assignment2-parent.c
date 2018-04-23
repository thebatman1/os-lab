#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
	pid_t return_val;
	int status;
	printf("Hello from main()\n");
	printf("The process id is: %d\n", getpid());
	return_val = fork();
	if (return_val > 0) {
		wait(&status);
		printf("Hello again from main()\n");
		printf("The process id is: %d\n", getpid());
	}
	else if (return_val == 0) {
		printf("Hello from child() %d\n", return_val);
		printf("The process id is: %d\n", getpid());
		printf("The parent process id is: %d\n", getppid());
		execvp("./3-assignment2-child", (char * const *)0);
	}
	else {
		fprintf(stderr, "Could not create a child process!\n");
	}
	return 0;
}
