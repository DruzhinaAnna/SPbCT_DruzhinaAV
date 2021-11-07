#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <iostream>
#include <sys/stat.h>
using namespace std;
int main()
{
	int fd, x;
	char buffer[1024];
	string text;
	char file;
	cout << "Введите 1 (прочитать из STDIN_FILENO) или 2 (прочитать из файла): ";
	cin >> x;
	while (x != 1 && x != 2)
	{
		cout << "Вы ввели неправильное значение. Введите снова:  ";
		cin >> x;
	}
	switch (x)
	{
		case 1: 
			cout << "\nВведите текст:\n";
			if (read(STDIN_FILENO, buffer, 1025) == EOF) 
			{
				printf("Чтение произвелось до конца файла\n"); 
				exit(1);
			}
			else
			{
				text = buffer;
				cout << "Kоличество прочитанных байт: " << text.length() - 1 << endl;
				break;
			}
		}
		case 2: 
		{
			if ((fd = open("file.txt", O_RDONLY)) == -1) 
			{
				printf("Невозможно открыть файл\n");
				exit(1);
			}
			if (read(fd, buffer, 1025) !=-1) 
				cout << "Чтение файла произведено до конца\n";
			text = buffer;
			cout << "\nПрочитанный текст:\n"<<text<<endl;
			cout << "Kоличество прочитанных байт: " << text.length()-1<<endl;
			break;
		}
	}
	return 0;
}