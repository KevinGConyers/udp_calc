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
unsigned char incoming_request_header[REQ_SIZE];

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

void sendAndRec() {
	while(1)
	{
		printf("Waiting for data...");
		fflush(stdout);

		//try to receive some data, this is a blocking call
		if ((recv_len = recvfrom(s, incoming_request_header, REQ_SIZE, 0, (struct sockaddr *) &si_other, &slen)) == -1)
		{
			die("recvfrom()");
		}

		//print details of the client/peer and the data received
		printf("Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
		printArray(incoming_request_header, REQ_SIZE);

		//now reply the client with the same data
		if (sendto(s, "msg recieved", recv_len, 0, (struct sockaddr*) &si_other, slen) == -1)
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
