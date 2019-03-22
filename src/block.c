#include <stdlib.h>
#include <stdio.h>

#include "utils/exit_status.h"
#include "block.h"

struct block* block_new(char* data, char* prevhash)
{
	struct block* blk = malloc(sizeof(struct block));
	if(blk == NULL)
		exit(EXIT_MEMORY_ALLOCATION);

	blk->data = data;
	blk->prevhash = prevhash;
	blk->timestamp = time(0);
	blk->nonce = 0;

	blk->hash = prochash(blk);

	return blk;
}

char* prochash(struct block* blk)
{
	
}

int chkb(char* hash, long difficulty){
	for(int i = 0; i < difficulty; i++) {
		if(hash[i] != '0')
			return 0;
	}
	return 1;
}

void mine(struct block* blk, long difficulty)
{
	while(chkb(blk->hash, difficulty)) {
		blk->nonce++;
		blk->hash = prochash(blk);
	}
	printf("Mined a block: %s", blk->hash);
}
