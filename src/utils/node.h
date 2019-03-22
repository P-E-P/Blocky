#ifndef _NODE_H
#define _NODE_H

struct node
{
	void* data;
	struct node *next;
};

struct node_bin
{
	void* data;
	struct node_bin *left, *right;
};

struct node_x
{
	void* data;
	struct node_x** sons;
	int size;
};

struct node* node_new(void*);
void node_del(struct node*);

struct node_bin* node_bin_new(void*);
void node_bin_del(struct node_bin*);

struct node_x* node_x_new(void*, int size);
void node_x_del(struct node_x*);

#endif
