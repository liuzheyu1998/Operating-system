int scheduler();
void initReadyQueue();
int scheduler();
int myinit(char * filename);
void addToReady(struct PCB * pcb);
void removeFromReady(struct PCB * pcb);
void moveToTail(struct PCB * pcb);
