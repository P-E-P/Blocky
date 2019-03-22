#ifndef _LIST_H
#define _LIST_H

struct list
{
	struct node* first;
	int size;
};


struct list* list_new();
void list_del(struct list*);
void list_append(struct list*, void*);
void* list_pop(struct list*, unsigned int);
void list_insert(struct list*, void*, unsigned int);
void* list_get(struct list*, unsigned int);
void list_set(struct list*, void*, unsigned int);

int list_empty(struct list*);
void list_print(struct list*);
#endif
