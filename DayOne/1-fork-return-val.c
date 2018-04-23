#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
	pid_t return_val;
	printf("Hello from main()\n");
	return_val = fork();
	if (return_val > 0)
		printf("Hello again from main() %d\n", return_val);
	else if (return_val == 0)
		printf("Hello from child() %d\n", return_val);
	else 
		fprintf(stderr, "Could not create a child process!\n");
	return 0;
}
