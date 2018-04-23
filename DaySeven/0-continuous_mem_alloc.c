#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
	if (argc < 3) {
		fprintf(stderr, "Usage: ./cont-alloc no_of_files no_of_blocks\n");	
		return 1;
	}
	int n,f,s,r;
	n = atoi(argv[2]);
	f = atoi(argv[1]);
	int blocks[n+1];
	memset(blocks, -1, sizeof(blocks));
	for (int i = 0; i < f; ++i)
	{
		printf("\nEnter details of file %d\n", i+1);
		printf("Required no. of blocks : ");
		scanf("%d", &r);
		printf("Starting position : ");
		scanf("%d", &s);
		bool flag=true;
		for (int j = s; j<s+r ; ++j)
		{
			if(blocks[j]==-1)
			{
				continue;
			}
			printf("Unsuccessful!\n");
			flag = false;
			break;
		}
		if(flag)
		{
			for (int j = s; j<s+r ; ++j)
			{
				blocks[j] = i+1;
			}
			printf("Success!\n");
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		printf("%d\t%d\n", i,blocks[i]);
	}
	return 0;
}

