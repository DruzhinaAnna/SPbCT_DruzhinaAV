#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{

	int x, pid;
	x = 2;
	printf("Single process, x=%d\n", x);
	pid = fork();
	if (pid == 0)
		printf("New, x=%d\n", x); 
	else if (pid > 0)
	{ 
		printf("Old, pid=%d, x=%d\n", pid, x);
		sleep(5);
		x = wait(&pid);
	}
	else {
		perror("Fork error ");
		return -1;
	}
	return 0;
}