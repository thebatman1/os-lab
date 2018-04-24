#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#define SIZE 25

int isPrime(int);

int main(void) {
	pid_t pid;
	int pfd[2];
	static unsigned int ar[SIZE], br[SIZE];
	if (pipe(pfd) == -1) {
		perror("Pipe error");
		exit(1);
	}
	if (( pid = fork() ) == -1 ) {
		perror("Fork error");
		exit(1);
	} else if ( pid == 0 ) {
		printf("\nChild generates fibonacci numbers!\n");
		int f1 = -1, f2 = 1, f3;
		for (int i = 0; i < SIZE; ++i) {
			f3 = f1 + f2;
			printf("%d ", f3);
			f1 = f2;
			f2 = f3;
			ar[i] = f3;
		}
		write(pfd[1], ar, SIZE * sizeof(int));
	} else {
		wait(NULL);
		printf("\nParent receives the fibonacci numbers and prints the prime ones!\n");
		read(pfd[0], br, SIZE * sizeof(int));
		for (int i = 0; i < SIZE; ++i) {
			if (isPrime(br[i])) {
				printf("%d ", br[i]);	
			}
		}
		printf("\n\n");
	}
}

int isPrime(int n) {
	if (n < 2) return 0;
	int flag = 1;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			flag = 0;
			break;
		}					
	}
	return flag;
}
