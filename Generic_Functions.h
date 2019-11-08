#include <stdio.h>
#include <stdlib.h>
#define REQ_SIZE 8
#define RES_SIZE 7
#define PLUS_OP_CODE 0
#define MINS_OP_CODE 1
#define MULT_OP_CODE 2
#define DIVS_OP_CODE 3
#define SHFL_OP_CODE 4
#define SHFR_OP_CODE 5
#define NOTS_OP_CODE 6

void printArray(unsigned char * buffer, int size) {
	int i  = 0;
	printf("|");
	for(i = 0; i < size; ++i) {
		printf("%i|", buffer[i]);
	}
	printf("\n");	
}
