unsigned char * serialize_request(unsigned char *buffer, char tml, char id, char op_code, int num_ops, short operand_one, short operand_two);
unsigned char * serialize_reponse(unsigned char *buffer, char tml, char id, char err0, int answer);

unsigned char * serialize_shrt(unsigned char * buffer, short value);


