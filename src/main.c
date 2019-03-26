#include <stdio.h>
#include <stdlib.h>

#include "blockchain.h"

int main(void)
{
	struct blockchain* blocky = blockchain_new();

	char f1[] = "12345";
	char f2[] = "Data in the second block";
	blockchain_add(blocky, f1);
	printf("Mining block 1...\n");
	mine(blocky->last, DIFFICULTY);

	blockchain_add(blocky, f2);
	printf("Mining block 2...\n");
	mine(blocky->last, DIFFICULTY);

	printf("\n\n");
	blockchain_print(blocky);
	
	printf("Deleting blockchain\n");
	blockchain_del(blocky);
}
