#include "linkedList.h"

LinkedList* ll_create(unsigned char isDynamic) {
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));

	if (list == NULL) {
		fprintf(stderr, "ERROR: failed to allocate memory for LinkedList\n");
		return NULL;
	}

	list->head = NULL;
	list->metaData = 0x00;

	if (isDynamic)
		list->metaData = list->metaData | 0x01;

	return list;
}

void ll_prepend(LinkedList* list, const void* value) {
	if (list == NULL) return;

	node* htemp = list->head;

	node* n = (node*)malloc(sizeof(node));

	if (n == NULL) {
		fprintf(stderr, "ERROR: failed to allocate memory for LinkedList\n");
		return;
	}

	n->next = htemp;
	n->value = value;

	list->head = n;
}

unsigned char ll_isEmpty(const LinkedList* list) {
	if (list == NULL) return 0;

	return list->head == NULL;
}

void* ll_popHead(LinkedList* list) {
	if (list == NULL) return NULL;

	node* newHead = list->head->next;
	void* value = list->head->value;

	unsigned char isDynamic = list->metaData & 0x01;

	if(isDynamic)
		free(list->head);

	list->head = newHead;

	return value;
}

void ll_clear(LinkedList* list) {
	if (list == NULL) return;

	unsigned char isDynamic = list->metaData & 0x01;

	while (list->head != NULL) {
		void* value = ll_popHead(list);

		if (isDynamic)
			free(value);
	}
}

void ll_delete(LinkedList* list) {
	if (list == NULL) return;

	unsigned char isDynamic = list->metaData & 0x01;

	while (list->head != NULL) {
		void* value = ll_popHead(list);

		if (isDynamic)
			free(value);
	}

	free(list);
}