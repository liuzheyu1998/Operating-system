#include "pcb.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>



struct PCB * makePCB(int start, int end) {
	struct PCB * temp = (struct PCB *) malloc(sizeof(struct PCB));
	//printf("I am here\n");
	//loadRam(filename, &(temp->start), &(temp->end));
	//printf("I am here\n");
	temp->PC = start;
	temp->start = start;
	temp->end=end;
	//printf("%d\n",temp->end);
	temp->next = NULL;
	return temp;
}


