#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

char * formatTime(unsigned long);

int main(int argc, char ** argv) {
	if (argc < 2) {
		fprintf(stderr, "Usage: ./a.out filename\n");
		exit(1);
	}	
	struct stat f1;
	if (stat(argv[1], &f1) == -1) {
		perror("Error");
		exit(1);
	}
	char * atime = formatTime(f1.st_atime);
	char * ctime = formatTime(f1.st_ctime);
	char * mtime = formatTime(f1.st_mtime);
	printf("File user id: %d\n", f1.st_uid);
	printf("File group id: %d\n", f1.st_gid);
	printf("File size: %ld\n", f1.st_size);
	printf("File block size: %ld\n", f1.st_blksize);
	printf("File block count: %ld\n", f1.st_blocks);
	printf("File dev_id: %lu\n", f1.st_dev);
	printf("File was accessed at: %s\n", atime);
	printf("File permissions were modified at: %s\n", ctime);
	printf("File was modified at: %s\n", mtime);
	printf("File permissions: ");
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
	printf("\n");
	free(atime);
	free(ctime);
	free(mtime);
	return 0;
}

char * formatTime(unsigned long timeInMS) {
	time_t timer = (time_t)timeInMS;
	char * buffer = (char *) malloc (sizeof(char) * 26);
	struct tm * tm_info;
	time(&timer);
	tm_info = localtime(&timer);
	strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
	return buffer;
}
