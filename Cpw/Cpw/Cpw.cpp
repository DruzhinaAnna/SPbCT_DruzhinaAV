#include<windows.h>
#include<stdio.h>
#include<locale>
#define BUF_SIZE 512
using namespace std;
int main(int argc, LPTSTR argv[])
{
	setlocale(LC_ALL, "1251");
	HANDLE hIn, hOut;
	DWORD nIn, nOut;
	CHAR Buffer[BUF_SIZE];
	if (argc != 3)
	{
		printf("Использование: CpW File1 File2\n");
		return 1;
	}
	hIn = CreateFile(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (hIn == INVALID_HANDLE_VALUE)
	{
		printf("Нельзя открыть входной файл. Ошибка: %x\n", GetLastError());
		return 2;
	}
	hOut = CreateFile(argv[2], GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hOut == INVALID_HANDLE_VALUE)
	{
		printf("Нельзя открыть выходной файл. Ошибка: %x\n", GetLastError());
		return 3;
	}
	while (ReadFile(hIn, Buffer, BUF_SIZE, &nIn, 0) && nIn > 0)
	{
		WriteFile(hOut, Buffer, nIn, &nOut, 0);
		if (nIn != nOut)
		{
			printf("Неисправимая ошибка записи : % x\n", GetLastError());
			return 4;
		}
	}
	CloseHandle(hIn);
	CloseHandle(hOut);
	return 0;
}
