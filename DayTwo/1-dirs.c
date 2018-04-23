#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

int main(void) {
	struct dirent *dptr;
	DIR *dp;
	if ((dp = opendir(".")) == NULL) {
		fprintf(stderr, "Error: %s\n", strerror(errno));	
		exit(1);
	}
	if (dp) {
		while(dptr = readdir(dp)) {
			printf("%s\n", dptr->d_name);	
		}	
		if (closedir(dp) == -1) {
			fprintf(stderr, "Error: %s\n", strerror(errno));
			exit(1);
		}
	}	
	return 0;
}
