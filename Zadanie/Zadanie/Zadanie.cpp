#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <locale>

int main()
{
	setlocale(LC_ALL, "rus");
	int x = 5, pid;
	FILE* File;
	File = fopen("file.txt", "w");
	fprintf(File, "�������, x = %d\n", x);
	printf("�������, x = %d\n", x);
	x++;
	fprintf(File, "����� ++, x = %d\n", x);
	printf("����� ++, x = %d\n", x);
	pid = fork();
	if (pid == 0) {
		fprintf(File, "\n������� 1, x = %d\n", x);
		printf("\n������� 1, x = %d\n", x);
		x -= 3;
		fprintf(File, "������� 2, x = %d\n", x);
		printf("������� 2, x = %d\n", x);
	}
	else if (pid > 0) { //
		fprintf(File, "\n�������� 1, x = %d, pid = %d\n", x, pid);
		printf("\n�������� 1, x = %d, pid = %d\n", x, pid);
		x += 2;
		fprintf(File, "�������� 2, x = %d\n", x);
		printf("��������  2, x = %d\n", x);
		sleep(5);
		waitpid(pid, NULL, NULL);
	}
	else {
		perror("Fork error ");
		return -1;
	}
	return 0;
}