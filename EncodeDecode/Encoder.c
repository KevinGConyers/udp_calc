#include "Encoder.h"
#include <stdio.h>

void serialize_request(char *buff, struct Request req){
	buff = (char *) &req;
}
void serialize_response(char *buff, struct Response resp) {
	buff = (char *) &resp;
}


unsigned char * serialize_int(unsigned char *buffer, int value) {
	buffer[0] = value >> 24;
	buffer[1] = value >> 16;
	buffer[2] = value >> 8;
	buffer[3] = value;

	return buffer + 4;
}
unsigned char * serialize_char(unsigned char *buffer, char value) {
	buffer[0] = value;

	return buffer + 1;
}
unsigned char * serialize_short(unsigned char *buffer, short value) {
	buffer[0] = value >> 8;
	buffer[1] = value;
	return buffer + 2;
}
/*
int main(void) {
	unsigned char * testBuffer;
	testBuffer = serialize_int(testBuffer, 400);
	for( int i = 0; i < 4; ++i) {
		//printf("%s", testBuffer[i]);
	}
}*/
