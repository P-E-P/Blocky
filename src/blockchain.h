#ifndef _BLOCKCHAIN_H
#define _BLOCKCHAIN_H

#include "block.h"

struct blockchain {

	struct block* first;
	struct block* last;
	size_t size;
};

struct blockchain* blockchain_new();
void addblock(char*, char*);
int validate(struct blockchain*);
void blockchain_print(struct blockchain*);
#endif
