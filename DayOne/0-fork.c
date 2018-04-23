#include <stdio.h>
#include <unistd.h>

int main(void) {
	printf("Hello 1\n");
	fork();
	fork();
	fork();
	printf("Hello 2\n");
	return 0;
}
