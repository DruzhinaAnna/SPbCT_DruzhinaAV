﻿#include <stdlib.h>
#include <stdio.h>
#define A_MEGABYTE (1024 * 1024)
#define PHY_MEM_MEGS 1024 /* Откорректируйте это число
 должным образом */
int main() {
	char* some_memory;
	size_t size_to_allocate = A_MEGABYTE;
	int megs_obtained = 0;
	while (megs_obtained < (PHY_MEM_MEGS * 2)) {
		some_memory = (char*)malloc(size_to_allocate);
		if (some_memory != NULL) {
			megs_obtained++;
			sprintf(some_memory, "Hello World");
			printf("%s — now allocated %d Megabytesn", some_memory, megs_obtained);
		}
		else {
			exit(EXIT_FAILURE);
		}
	}
	exit(EXIT_SUCCESS);
}