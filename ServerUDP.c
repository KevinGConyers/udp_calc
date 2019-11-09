//Server side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include "ServerUDP.h"


#define MAXLINE 1024 

// Driver code 

#define BUFLEN 512	//Max length of buffer
struct sockaddr_in si_me, si_other;

int s,   recv_len;
unsigned int slen = sizeof(si_other);
char buf[BUFLEN];

void die(char *s)
{
	perror(s);
	exit(1);
}

int setUp(int port) {
	// zero out the structure
	memset((char *) &si_me, 0, sizeof(si_me));
	si_me.sin_family = AF_INET;
	si_me.sin_port = htons(port);
	si_me.sin_addr.s_addr = htonl(INADDR_ANY);

	//bind socket to port
	if( bind(s , (struct sockaddr*)&si_me, sizeof(si_me) ) == -1)
	{
		return -1;
	}
	return 0;
}
int performCalculation(unsigned char * buffer) {
	int ret = 0;
	short operand_one = deserialize_shr(buffer, 4);
	short operand_two = deserialize_shr(buffer, 6);
	const char operation = deserialize_char(buffer, 2);
	printf("Operation Code: %i\n", operation);
	printf("Operand One: %i\n", operand_one);
	printf("Operand Two: %i\n", operand_two);
	switch (operation) {
		case (0) :
			ret = operand_one + operand_two;
			break;
		case (1) :
			ret = operand_one - operand_two;
			break;
		case (2) :
			ret = operand_one * operand_two;
			break;
		case (3) :
			ret = operand_one / operand_two;
			break;
		case (4) :
			ret = operand_one >> 1;
			 break;
		case (5) :
			 ret = operand_one << 1;
			 break;
		case (6) :
			 ret = ~operand_one;
	}
	printf("Answer: %i\n", ret);
	return ret;
}

void sendAndRec() {
	while(1)
	{
		printf("Waiting for data...");
		fflush(stdout);

		unsigned char incoming_request_header[REQ_SIZE];
		unsigned char outgoing_response_header[RES_SIZE];
		//try to receive some data, this is a blocking call
		if ((recv_len = recvfrom(s, incoming_request_header, REQ_SIZE, 0, (struct sockaddr *) &si_other, &slen)) == -1)
		{
			die("recvfrom()");
		}
		int answer = performCalculation(incoming_request_header);
		char err0 = 0;
		char size = deserialize_char(incoming_request_header, 0);
		char id = deserialize_char(incoming_request_header, 1);
		if (size != sizeof(incoming_request_header)) {
			err0 = 127;
		}
		unsigned char * outgoing_answer = serialize_response(outgoing_response_header, RES_SIZE, id, err0, answer);
		//print details of the client/peer and the data received
		
		printf("Sending Out this packet: ");
		printArray(outgoing_response_header, RES_SIZE);

		//now reply the client with the same data
		if (sendto(s, outgoing_answer, RES_SIZE, 0, (struct sockaddr*) &si_other, slen) == -1)
		{
			die("sendto()");
		}
	}


}

int main(int argc, char const *argv[])
{
	if(argc < 2) {
		die("Syntax is: \'Server [port]\'");
	}

	//create a UDP socket
	if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
	{
		die("socket");
	}

	if (setUp(atoi(argv[1])) < 0) {
		die("setup failed");
	}

	sendAndRec();
	close(s);
	return 0;
}
