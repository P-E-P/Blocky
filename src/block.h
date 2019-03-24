#ifndef _BLOCK_H
#define _BLOCK_H

#include <time.h>

struct block
{
	char *hash, *prevhash;
	char* data;
	time_t timestamp;
	int nonce;

	struct block* next;
	struct block* prev;
};

struct block* block_new(char*, char*);
char* prochash(struct block*);
void printhash(unsigned char* hash);
void mine(struct block*, long);
void block_print(struct block*);
#endif
