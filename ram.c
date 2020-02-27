#include "ram.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char * ram[1000];

int initRam() {
	for (int i = 0; i < 1000; i++) {
		ram[i]=NULL;
	}
	return 0;
}
//TODO: addToRam take *p not filename
void addToRam(FILE *p, int *start, int* end) {
	char buffer[1000];
	int i = 0;
	*start =0;
	*end =0;

	while (ram[i] != NULL) {
		i++;
		//printf("i=%d\n",i);
	}
	*start = i;
	//printf("\n\n\n");
	//TODO:each file can take at most 333 lines
	while (i < 1000 && fgets(buffer, 999, p) != NULL) {
		ram[i] = strdup(buffer);
		//printf("%d, %s\n",i, ram[i]);
		i++;
	}
	//printf("\n\n\n");

	*end = i - 1;
	//printf("%d,%d\n", *start, *end);
	//TODO: Do I need to let rest of the ram points to NULL
	//return 0;
}

char * getRam(int PC) {
	char *temp;
	temp = strdup(ram[PC]);
	//printf("\n%d, %s\n",PC, temp);
	return temp;
}

int freeRam(){
	for (int i = 0; i < 1000; i++) {
			ram[i]=NULL;
		}
		return 0;
}

