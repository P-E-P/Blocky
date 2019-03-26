#ifndef _BLOCKCHAIN_H
#define _BLOCKCHAIN_H

#include "block.h"

#define DIFFICULTY 2

struct blockchain {

	struct block* first;
	struct block* last;
	size_t size;
};

struct blockchain* blockchain_new();
void blockchain_del(struct blockchain*);
void blockchain_del_lastb(struct blockchain*);
void blockchain_add(struct blockchain*, char*);
int validate(struct blockchain*);
void blockchain_print(struct blockchain*);
#endif
