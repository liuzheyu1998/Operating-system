#include "interpreter.h"
#include "ram.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct CPU {
	int IP;
	char *IR;
	int quanta;
};

struct CPU *cpu=NULL;

void initCPU(){
	struct CPU *temp = (struct CPU *) malloc(sizeof(struct CPU));
	cpu=temp;
	cpu->IP=0;
}

//int processCPU(struct PCB * pcb) {
//	struct CPU *temp = (struct CPU *) malloc(sizeof(struct CPU));
//	cpu=temp;
//	cpu->quanta = 2;
//	cpu->IP = (pcb)->PC;
//	cpu->IR = strdup(getRam(cpu->IP));
//	while (cpu->quanta > 0) {
//		//TODO: Check if it is interpret or others
//		cpu->IR = strdup(getRam(pcb->PC));
//		interpret(cpu->IR);
//		//printf("%d\n", cpu->quanta);
//		cpu->quanta--;
//		int stop = incPCB(pcb);
//		if (stop > 0)
//			return 20; // indicate the last line of the file
//
//	}
//	return 21; //indicate the script is not finished processing, it need to be moved to the tail of the ready queue
//
//}
int run(int quanta){
	if(cpu==NULL){
		initCPU();
	}
	cpu->quanta = quanta;
	while (cpu->quanta > 0) {
			//TODO: Check if it is interpret or others
			cpu->IR = strdup(getRam(cpu->IP));
			//printf("%s\n",cpu->IR);
			int status = interpret(cpu->IR);
			if (status == 100){
				//printf("One script\n");
				return 100;
			}
			//printf("%d\n", cpu->quanta);
			cpu->quanta--;
			cpu->IP = (cpu->IP) + 1;

		}
		//return 21; //indicate the script is not finished processing, it need to be moved to the tail of the ready queue
		return 0;
}

void setIP(int PC){
	cpu->IP=PC;
}

struct CPU * getCPU() {
	return cpu;

}
