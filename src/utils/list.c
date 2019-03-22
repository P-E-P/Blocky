#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "list.h"
#include "exit_status.h"


struct list* list_new()
{
	struct list* l = malloc(sizeof(struct list));

	if(l == NULL)
		exit(EXIT_MEMORY_ALLOCATION);

	l->size = 0;
	l->first = NULL;

	return l;
}

void list_del(struct list* l)
{
	if(l){
		while(!list_empty(l))
			list_pop(l, 0);
		free(l);
	}
}

void list_append(struct list* l, void* data)
{
	if(l->size == 0){
		l->first = node_new(data);
	}else{
		struct node* ret = l->first;
		for(unsigned int i = 0; i < l->size - 1;i++){
			ret = ret->next;
		}
		ret->next = node_new(data);
	}
	l->size++;
}

void list_insert(struct list* l, void* data, unsigned int index)
{
	if(l->size == 0){
		l->first = node_new(data);
	}else{
		struct node* nw = node_new(data);
		if(index == 0){
			nw->next = l->first;
			l->first = nw;
		}
		else{
			struct node* tmp = l->first;
			for(unsigned int i = 0; i < index - 1 && i < l->size - 1; i++){
				tmp = tmp->next;
			}
			nw->next = tmp->next;
			tmp->next = nw;
		}
	}
	l->size++;
}

void* list_pop(struct list* l, unsigned int index)
{
	if(list_empty(l) || index >= l->size)
		exit(EXIT_NULL_POINTER);

	void* ret;
	if(l->size > 1){
		struct node* tmp = l->first;
		if(index == 0){
			ret = l->first->data;
			l->first = tmp->next;
			node_del(tmp);
		}
		else{
			for(unsigned int i = 0; i < index - 1; i++){
				tmp = tmp->next;
			}
			struct node* err = tmp->next;
			tmp->next = err->next;
			ret = err->data;
			node_del(err);
		}
	}else{
		ret = l->first->data;
		node_del(l->first);
		l->first = NULL;
	}
	
	l->size--;
	return ret;
}

void* list_get(struct list* l, unsigned int index)
{
	if(index >= l->size)
		exit(EXIT_NULL_POINTER);
	struct node* ret = l->first;
	for(unsigned int i = 0; i < index; i++){
		ret = ret->next;
	}
	return ret->data;
}

void list_set(struct list* l, void* data, unsigned int index)
{
	struct node* ret = l->first;
	
	if(index >= l->size)
		exit(EXIT_NULL_POINTER);
	
	for(unsigned int i = 0; i < index; i++){
		ret = ret->next;
	}
	ret->data = data;
}

void list_print(struct list* l)
{
	struct node* ret = l->first;
	printf("[");
	for(unsigned int i = 0; i < l->size; i++){
		printf("%i,",*(int*)ret->data);
		ret = ret->next;
	}
	printf("]");
}

int list_empty(struct list* l)
{
	return l->size == 0;
}
