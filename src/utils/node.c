#include <stdlib.h>

#include "exit_status.h"
#include "node.h"


struct node* node_new(void* data)
{
	struct node* n = malloc(sizeof(struct node));
	if(n == NULL)
		exit(EXIT_MEMORY_ALLOCATION);

	n->data = data;

	return n;
}

void node_del(struct node* n)
{
	if(n){
		free(n);
	}
}

struct node_bin* node_bin_new(void* data)
{
	struct node_bin* n = malloc(sizeof(struct node_bin));
	if(n == NULL)
		exit(EXIT_MEMORY_ALLOCATION);

	n->data = data;
	n->left = NULL;
	n->right = NULL;

	return n;
}

void node_bin_del(struct node_bin* n)
{
	if(n){
		free(n);
	}
}


struct node_x* node_x_new(void* data, int size)
{
	struct node_x* n = malloc(sizeof(struct node_x));
	if(n == NULL)
		exit(EXIT_MEMORY_ALLOCATION);
	
	n->sons = malloc(sizeof(struct node_x*) * size);
	if(n == NULL)
		exit(EXIT_MEMORY_ALLOCATION);

	n->size = size;
	n->data = data;

	return n;
}


void node_x_del(struct node_x* n)
{
	if(n){
		free(n->sons);
		free(n);
	}
}
