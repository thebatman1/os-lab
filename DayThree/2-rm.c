#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char ** argv) {
	if (argc < 2) {
		fprintf(stderr,"Usage: ./a.out filename\n");
		exit(1);
	}
	struct stat f1;
	char * filename = argv[1];
	if (stat(filename, &f1) == -1) {
		perror("Stat");
		exit(1);
	}
	if (unlink(filename) == 0) {
		printf("%s removed successfully\n", filename);
	} else {
		perror("Remove");
		exit(1);
	}
	return 0;
}

