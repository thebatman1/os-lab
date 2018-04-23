#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>

int main(void) {
	DIR * dp;
	struct dirent * dptr; 
	if ((dp = opendir(".")) == NULL) {
		perror("Opendir");
		exit(1);
	}
	int count = 0;
	if (dp) {
		while(dptr = readdir(dp)) {
			char * filename = dptr->d_name;
			if (filename[0] != '.') {
				printf("%-20s  ", dptr->d_name);
				count = (count + 1)%8;
				if (count == 0) printf("\n");
			}
		}
		if (closedir(dp) == -1) {
			fprintf(stderr, "Error: %s\n", strerror(errno));
			exit(1);
		}
		printf("\n");
	}

	return 0;
}
