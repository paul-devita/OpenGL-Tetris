#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdlib.h>
#include <stdio.h>

#define LL_FALSE 0
#define LL_TRUE 1

#define LL_ISDYNAMIC 1

typedef struct {
	void *value;
	node* next;
} node;

typedef struct {
	node* head;
	unsigned char metaData;
} LinkedList;

LinkedList* ll_create(unsigned char isDynamic);

void ll_prepend(LinkedList* list, const void* value);

unsigned char ll_isEmpty(const LinkedList* list);

void* ll_popHead(LinkedList* list);

void ll_clear(LinkedList* list);

void ll_delete(LinkedList* list);

#endif