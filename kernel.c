#include "pcb.h"
#include "cpu.h"
#include "kernel.h"
#include "ram.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct PCB *head, *tail;

void initReadyQueue() {
	head = NULL;
	tail = NULL;

}
//SCHEDULER: after the initiation
/*
 * Initiation: in the exec and then exec call the scheduler
 * 1. create pcb
 * 2. add to the ready queue
 *
 * scheduler:
 * 1. use a while loop
 * 2. then run cpu, after the quanta is used
 * 3. check if it is the last line, if it is then remove from the queue
 * 4. move the current lcb to tail
 *
 *
 * One more thing need to check, if the queue and all pcb are freed before they are used again
 */
//int scheduler() {
//	while (1) {
//		struct PCB * head = getHead();
//
//		int end = processCPU(head);
//		if (end == 20)
//			removeFromReady(head);
//			if (head==NULL) break;//if nothing left in the queue, then check the head if it is null
//		else
//			moveToTail(head);
//	}
//	return 0;
//}

int scheduler() {

	//initReadyQueue();
	initCPU();
	while (1) {
		struct PCB* cur = head;

		if(cur==NULL){
			break;
		}

		int curPC = cur->PC;
		int end = cur->end;
//		printf("I am here\n");
//		printf("%d\n",curPC-end);
		setIP(curPC);

		if(end-curPC>1){
			int status = run(2);
			if (status == 100){
				removeFromReady(head);
				//printf("One script\n");
			}
			else{
			cur->PC= cur->PC + 2;
			moveToTail(head);
			}
		}else if(end-curPC==1){
			int status = run(2);
			if (status == 100){
				removeFromReady(head);
				//printf("One script\n");
			}else{
			removeFromReady(head);
			}
		}else if(end-curPC ==0){
			int status = run(1);
			if (status == 100){
				removeFromReady(head);
			}else{
			removeFromReady(head);
			}
		}else{
			removeFromReady(head);
		}


	}
	return 0;
}

//struct PCB * getHead() {
//	return head;
//}

int myinit(char * filename){
	FILE *p = fopen(filename, "rt");
	if (p == NULL)
	{
		printf("Script not found.\n");
		return 1;
	}
	int start;
	int end;
	addToRam(p,&start,&end);
	struct PCB * new = makePCB(start,end);
	addToReady(new);
	return 0;
//	if (head == NULL) {
//		printf("head is null\n");
//	}
//	else printf("not null\n");
}

void addToReady(struct PCB * pcb) {
	if (head == NULL) {
		head = pcb;
		head->next = NULL;
		tail = pcb;
		tail->next = head;
	} else {
		tail->next = pcb;
		tail = pcb;
		tail->next = head;
	}
}

//TODO:the logic of this method has not been tested yet

void removeFromReady(struct PCB * pcb) {
	if (pcb == NULL) {
		printf("Error: Did not find this PCB, please check the start number.");
	}
	struct PCB * temp = pcb;
	if (head == pcb && tail == pcb) {
		head = NULL;
		tail = NULL;
	} else if (pcb->next->next==pcb) {
		head = head->next;
		head->next =head;
	} else if (pcb->next->next->next==pcb) {
		head = head->next;
		//head->next = tail;
		tail->next =head;
	}
	free(temp);
}

// should it change to a pointer????
void moveToTail(struct PCB * pcb) {
	if (pcb == NULL) {
		printf("Error: Did not find this PCB, please check again.");
	}
	if (head == tail) {
		return;
	} else {
		//tail->next = head;
		head = head->next;
		tail = tail->next;

		//tail->next=head;
	}
}

//int incPCB(struct PCB * pcb) {
//	int pc = (pcb)->PC;
//	int end = (pcb)->end;
//	if (pc == end) {
//		return 10;
//	} else {
//		(pcb)->PC++;
//		return 0;
//	}
//}




