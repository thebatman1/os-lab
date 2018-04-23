#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
	pid_t return_val = getpid();
	int i;
	long fact = 1;
	for (i = 1; i <= 7; ++i) {
		fact *= i;		
	}
	printf("7! = %ld\n", fact);
	printf("The process id is: %d\n", return_val);
	return 0;
}
