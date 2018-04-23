#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

int main(void) {
	struct stat f1;
	if (stat("0-stat.c", &f1) == -1) {
		fprintf(stderr, "Error: %s\n", strerror(errno));	
		exit(1);
	}
	printf("File user id: %d\n", f1.st_uid);
	printf("File group id: %d\n", f1.st_gid);
	printf("File size: %ld\n", f1.st_size);
	printf("File block size: %ld\n", f1.st_blksize);
	printf("File block count: %ld\n", f1.st_blocks);
	printf("File dev_id: %lu\n", f1.st_dev);
	printf("File was accessed at: %lu\n", f1.st_atime);
	printf("File permissions were modified at: %lu\n", f1.st_ctime);
	printf("File was modified at: %lu\n", f1.st_mtime);
	printf("File mode: %o\n", f1.st_mode);
	return 0;
}
