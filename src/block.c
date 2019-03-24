#include <stdlib.h>
#include <stdio.h>
#include <openssl/sha.h>
#include <string.h>

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

void printhash(unsigned char* hash){
	for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
		printf("%02x", hash[i]);
	printf("\n");
}

void block_print(struct block* b)
{
	printf("Data: %s,Time: %lu, Hash: ",b->data, b->timestamp);
	printhash((unsigned char*)b->hash);
	printf("\n");
}

char* prochash(struct block* b)
{
	char ibuf[1000];
	strcpy(ibuf, b->prevhash);
	strcat(ibuf, ctime(&b->timestamp));
	char nstr[19];
	snprintf(nstr, 19, "%d", b->nonce);
	strcat(ibuf,nstr); 
	strcat(ibuf, b->data);	
	unsigned char* ret = SHA256((unsigned char*)ibuf, strlen(ibuf), 0);
	return (char*)ret;
}

int chkb(char* hash, long difficulty){
	for(int i = 0; i < difficulty; i++) {
		if(hash[i] != '0')
			return 0;
	}
	return 1;
}

void mine(struct block* b, long difficulty)
{
	while(!chkb(b->hash, difficulty)) {
		b->nonce++;
		b->hash = prochash(b);
	}
	printf("Mined a block, new hash is:");
	printhash((unsigned char*)b->hash);
}
