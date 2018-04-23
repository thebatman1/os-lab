#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

int main(void) {
	//if file is not in directory, it will be created in READONLY MODE
	int rval;
	if ((rval = open("foo.txt", O_RDONLY | O_CREAT)) == -1) {
		perror("Error");
		exit(1);
	}
	printf("fd = %d\n", rval);
	return 0;
}
