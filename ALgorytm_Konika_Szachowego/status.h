#ifndef DEBUG
#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#endif // DEBUG

bool must_init(bool test,const char* description) {
	if (test) { return true; }
	else {
		printf("Cannot inicialize or value fault \n DESCRIPTION: %s", description);
		system("pause");
		exit(1);
	}
}