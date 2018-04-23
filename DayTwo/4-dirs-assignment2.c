#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char ** argv) {
	if (argc < 2) {
		fprintf(stderr, "Usage: ./a.out dirname\n");	
		exit(1);
	}
	struct dirent *dptr;
	struct stat f1;
	DIR *dp;
	if ((dp = opendir(argv[1])) == NULL) {
		perror("Error");	
		exit(1);
	}
	if (dp) {
		if (chdir(argv[1]) == -1) {
			perror("Chdir");
			exit(1);
		}
		while(dptr = readdir(dp)) {
			char * filename = dptr->d_name;
//			char name[100];
//			memset(name, '\0', sizeof(name));
//			strcpy(name, argv[1]);
//			name[strlen(name)] = '/';
			if (stat(filename, &f1) == -1) {
				perror("Stat");
				exit(1);
			}
			int mode = f1.st_mode;
			printf(S_ISDIR(mode)?"d":"-");
			printf((mode & S_IRUSR)?"r":"-");   
			printf((mode & S_IWUSR)?"w":"-");   
			printf((mode & S_IXUSR)?"x":"-");   
			printf((mode & S_IRGRP)?"r":"-");   
			printf((mode & S_IWGRP)?"w":"-");   
			printf((mode & S_IXGRP)?"x":"-");   
			printf((mode & S_IROTH)?"r":"-");   
			printf((mode & S_IWOTH)?"w":"-");   
			printf((mode & S_IXOTH)?"x":"-");   
			printf("  ");
			printf("%s\n", filename);	
		}	
		if (closedir(dp) == -1) {
			perror("Error");
			exit(1);
		}
	}	
	return 0;
}
