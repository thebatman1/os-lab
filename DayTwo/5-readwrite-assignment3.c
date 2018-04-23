#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char ** argv) {
	if (argc < 3) {
		fprintf(stderr, "Usage: ./a.out file1 file2\n");	
		exit(1);
	}
	struct stat f1;
	if (stat(argv[1], &f1) == -1) {
		perror("Error line 16");
		exit(1);
	}	
	//it will be created in READONLY MODE
	int rval, wval;
	char buff[1024];
	memset(buff, '\0', sizeof(buff));
	if ((rval = open(argv[1], O_RDONLY)) == -1) {
		perror("Error line 23");
		exit(1);
	}
	if (creat(argv[2], S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH) == -1) {
		perror("Error line 27");
		exit(1);
	}
	if ((wval = open(argv[2], O_WRONLY)) == -1) {
		perror("Error line 31");
		exit(1);
	}
	while(read(rval, buff, 1024) > 0) {
		write(wval, buff, strlen(buff));			
	}
	printf("File copied successfully!\n");
	close(rval);
	close(wval);
	return 0;
}
