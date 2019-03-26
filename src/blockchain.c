#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils/exit_status.h"
#include "blockchain.h"

struct blockchain* blockchain_new()
{
	struct blockchain* bc = malloc(sizeof(struct blockchain));
	if(bc == NULL)
		exit(EXIT_MEMORY_ALLOCATION);
	bc->first = NULL;
	bc->last = NULL;
	return bc;
}

void blockchain_del(struct blockchain* bc)
{
	while(bc->size != 0){
		blockchain_del_lastb(bc);
	}
	free(bc);
}

void blockchain_del_lastb(struct blockchain* bc)
{
	struct block* del = bc->last;
	bc->last = del->prev;
	bc->size--;
	free(del);
}

void blockchain_add(struct blockchain* bc, char* data)
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
	for(struct block* b = bc->first; b != NULL; b = b->next) {
		block_print(b);
	}
}
