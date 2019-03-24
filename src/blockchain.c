#include <stdlib.h>
#include <string.h>

#include "utils/exit_status.h"
#include "blockchain.h"

#define DIFFICULTY 8

struct blockchain* blockchain_new()
{
	struct blockchain* bc = malloc(sizeof(struct blockchain));
	if(bc == NULL)
		exit(EXIT_MEMORY_ALLOCATION);
	bc->first = NULL;
	bc->last = NULL;
	return bc;
}

void add(struct blockchain* bc, char* data)
{
	if(bc->size == 0) {
		bc->first = block_new(data, "0");
		bc->last = bc->first;
	} else {
		bc->last->next = block_new(data, bc->last->hash);
		bc->last->next->prev = bc->last;
		bc->last = bc->last->next;
	}
	bc->size++;
}

int validate(struct blockchain* bc)
{
	for(struct block* b = bc->first->next; b != NULL; b = b->next) {
		char* chash = prochash(b);
		// Verify current hash
		if(strcmp(chash, b->hash) != 0)
			return 0;
		free(chash);
		// Verify previous hash
		if(strcmp(b->prev->hash, b->prevhash) != 0)
			return 0;
		
		for(int i = 0; i < DIFFICULTY; i++){
			if(b->hash[i] != '0')
				return 0;
		}
	}
	return 1;
}

void blockchain_print(struct blockchain* bc)
{
	for(struct block* b = bc->first; b->next != NULL; b = b->next) {
		block_print(b);
	}
}
