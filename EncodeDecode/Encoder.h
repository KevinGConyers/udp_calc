#include "RequestResponse.h"

void serialize_request(char *buff, struct Request req);
void serialize_response(char *buff, struct Response resp);


unsigned char * serialize_int(unsigned char *buffer, int value);
unsigned char * serialize_char(unsigned char *buffer, char value);
unsigned char * serialize_shrt(unsigned char *buffer, short value);
