#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char ** argv) {
	if (argc < 3) {
		fprintf(stderr, "Usage: ./grep pattern filename");
		exit(1);
	}
	struct stat f1;
	if (stat(argv[2], &f1) == -1) {
		perror("Stat");
		exit(1);
	}	
	char * pattern = argv[1];
	char * filename = argv[2];
	FILE * fp;
	if ((fp = fopen(filename, "r")) == NULL) {
		perror("Open");
		exit(1);
	}
	char buffer[100];
	memset(buffer, '\0', sizeof(buffer));
	while (fgets(buffer, 100, fp) != NULL) {
		if (strstr(buffer, pattern) != NULL) {
			fprintf(stdout, "%s", buffer);	
			memset(buffer, '\0', sizeof(buffer));
		}	
	} 
	return 0;
}
