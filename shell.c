#include "interpreter.h"
#include "shellmemory.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[]) {
	printf("Kernel 1.0 loaded!");
	printf("Welcome to the Zheyu Liu's shell!\n"
			"Shell version 2.0 Updated February 2020\n");

	shell_memory_initialize();

	while (!feof(stdin)) {
		printf("$ ");
		fflush(stdout);

		char *line = NULL;
		size_t linecap = 0;
		if (getline(&line, &linecap, stdin) == -1)
			break;
		if (!isatty(0)) {
			printf("%s", line);
		}
		(void) interpret(line);
		free(line);
	}
	printf("Bye!\n");
	shell_memory_destory();

	return 0;
}
