#include "Encoder.h"
#include <stdio.h>
#include <limits.h>

unsigned char * serialize_request(unsigned char *buffer, char tml, char id, char op_code, int num_ops, short operand_one, short operand_two) {
	printf("op 1 in serialize: %i\n", operand_one);
	printf("op 2 in serialize: %i\n", operand_two);
	buffer[0] = tml;
	buffer[1] = id;
	buffer[2] = op_code;
	buffer[3] = num_ops;
	buffer[4] = operand_one >> 8;
	buffer[5] = operand_one;
	buffer[6] = operand_two >> 8;
	buffer[7] = operand_two;
	return buffer;
}



unsigned char * serialize_reponse(unsigned char *buffer, char tml, char id, char err0, int answer){
	buffer[0] = tml;
	buffer[1] = id;
	buffer[2] = err0;
	buffer[3] = answer >> 24;
	buffer[4] = answer >> 16;
	buffer[5] = answer >> 8;
	buffer[6] = answer;
	return buffer;

}

unsigned char * serialize_shrt( unsigned char * buffer, short value) {
	buffer[0] = (value >> 8) & 0xff;
	buffer[1] = value & 0xff;
	return  buffer;
}

