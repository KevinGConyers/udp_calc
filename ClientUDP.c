// Client side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <limits.h>
#include "ClientUDP.h"
#include "EncodeDecode/Encoder.c"
#include "EncodeDecode/Decoder.c"

#define MAXLINE 1024 

// Driver code 
#define SERVER "127.0.0.1"
#define BUFLEN 512	//Max length of buffer
#define PORT 8888	//The port on which to send data

struct sockaddr_in si_other;
int s;
unsigned int slen=sizeof(si_other);
char buf[BUFLEN];
char message[BUFLEN];
char id = 0;

void die(char *s)
{
	perror(s);
	exit(1);
}

int setUp(int port, char const *address) {

	memset((char *) &si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(port);

	if (inet_aton(address , &si_other.sin_addr) == 0) 
	{
		fprintf(stderr, "inet_aton() failed\n");
		return -1;
	}
	return 0;
}

unsigned char * generateRequest(unsigned char * buffer) {
	char op_code;
	char num_ops;
	short operand_one;
	short operand_two = 0;
	char msg_in[BUFLEN];
	printf("Enter operation (+ - * / >> << ~)");
	fgets(msg_in, BUFLEN, stdin);
	const char op_check = msg_in[0]; 
	switch (op_check) {
		case('+') :
			op_code = PLUS_OP_CODE;
			num_ops = 2;
			break;
		case('-') :
			op_code = 1;
			num_ops = 2;
			break;
		case('*') :
			op_code = 2;
			num_ops = 2;
			break;
		case('/') :
			op_code = 3;
			num_ops = 2;
			break;
		case('>') :
			op_code = 4;
			num_ops = 1;
			break;
		case('<') :
			op_code = 5;
			num_ops = 1;
			break;
		case('~') :
			op_code = 6;
			num_ops = 1;
			break;
		default:
			op_code = op_check;
			num_ops = '3';
			break;	
	}
	memset(msg_in, '\0', BUFLEN);
	printf("Enter operand_one: ");
	fgets(msg_in, BUFLEN, stdin);
	operand_one = atoi(msg_in);
	if (num_ops == 2) {
	printf("Enter operand_two: ");
	fgets(msg_in, BUFLEN, stdin);
	operand_two = atoi(msg_in);
	}
	return serialize_request(buffer, REQ_SIZE, ++id, op_code, num_ops, operand_one, operand_two);


}

void sendAndRec(){
	while(1)
	{
		unsigned char reqBuffer[REQ_SIZE];
		unsigned char * out = generateRequest(reqBuffer);
		unsigned char incoming_response_header[RES_SIZE];

		//send the message
		if (sendto(s, out, REQ_SIZE , 0 , (struct sockaddr *) &si_other, slen)==-1)
		{
			die("sendto()");
		}

		//clear the buffer by filling null, it might have previously received data
		memset(buf,'\0', BUFLEN);
		//receive a reply and print it
		//try to receive some data, this is a blocking call
		if (recvfrom(s, incoming_response_header, RES_SIZE, 0, (struct sockaddr *) &si_other, &slen) == -1)
		{
			die("recvfrom()");
		}
		int answer = deserialize_int(incoming_response_header, 3);
		char idIn = deserialize_char(incoming_response_header, 1);

		memset(reqBuffer, '\0', REQ_SIZE);

		printf("Header recieved from server: ");
		printArray(incoming_response_header, RES_SIZE);
		printf("\n");


		printf("Answer for request with Id %i: %i\n", idIn, answer);
	}
}



int main(int argc, char const *argv[])
{

	if(argc < 3) {
		printf("Syntax is: \'Client [server address] [port]\'\n");
		die("insufficient parameters");
	}

	if ( (s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
	{
		die("socket creation failure");
	}

	if (setUp(atoi(argv[2]), argv[1]) < 0) {
		printf("failed to set up");
		die("Set up failure");
	}


	sendAndRec();
	close(s);

	/*while(1) {
	unsigned char intBuffer[4];
	printf("enter val: ");
	fgets(message, BUFLEN, stdin);
	int value = atoi(message);
	printf("value: %i\n", value);
	unsigned char * out = serialize_int(intBuffer, value);
	printArray(out, 4);
	int recieInt = deserialize_int(out, 0);
	printf("Got: %i\n", recieInt);
	}*/
	
	return 0;
}
