// Client side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include "ClientUDP.h"
#include "EncodeDecode/RequestResponse.h"
  
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

int recvHeaderSize;

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
void sendAndRec(){
	while(1)
	{
		char id = 0;	
		struct Request * outGoingRequest = {'7', ++id, '0', '2', '-1', '-1'};
		printf("Enter operation (+ - * /): ");
		fgets(message, BUFLEN, stdin);
		char op = message[0];
		printf("passed assignment\n");
		switch(op) {
			case '+' :
				outGoingRequest->opCode = '0';
				outGoingRequest->numOps = '2';
				break;
			default :
				outGoingRequest->opCode = '-1';
		}
		printf("Enter operand one: ");
		fgets(message, BUFLEN, stdin);
		outGoingRequest->operand1 = atoi(message);
		if (outGoingRequest->numOps > 1) {
			printf("Enter operand two: ");
			fgets(message, BUFLEN, stdin);
			outGoingRequest->operand2 = atoi(message);

		}

		//send the message
		if (sendto(s, (struct Request*)&outGoingRequest, (1024+sizeof(outGoingRequest)), 0 , (struct sockaddr *) &si_other, slen)==-1)
		{
			die("sendto()");
		}
		
		//receive a reply and print it
		//clear the buffer by filling null, it might have previously received data
		memset(buf,'\0', BUFLEN);
		//try to receive some data, this is a blocking call
		if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen) == -1)
		{
			die("recvfrom()");
		}
		
		printf("Recieved from server: %s\n", buf);
	}
}

int main(int argc, char const *argv[])
{
	//struct sockaddr_in si_other;
	//int s;
	//unsigned int slen=sizeof(si_other);
	//char buf[BUFLEN];
	//char message[BUFLEN];
	
	if(argc < 3) {
		printf("Syntax is: \'Client [port] [server address]\'\n");
		die("insufficient parameters");
	}

	if ( (s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
	{
		die("socket creation failure");
	}

	if (setUp(atoi(argv[1]), argv[2]) < 0) {
		printf("failed to set up");
		die("Set up failure");
	}

	sendAndRec();
	close(s);
	return 0;
}
