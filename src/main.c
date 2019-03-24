#include <stdio.h>
#include <stdlib.h>

#include "blockchain.h"

int main(void)
{
	struct blockchain* blocky = blockchain_new();

	blockchain_print(blocky);
}
