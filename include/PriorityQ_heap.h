#ifndef __PQH__
#define __PQH__

#include <stdlib.h>
typedef struct pqh_node pqh_node_t;

struct pqh_node{
	int priority;
	void *data;
};

typedef struct {
	pqh_node_t *nodes;
	size_t elementSize;
	int numElements;
	int manElements;
} PriorityQHeap;

PriorityQHeap * pqh_new(size_t elementSize);
void pqh_free(PriorityQHeap *pqh);
void* pqh_delete_max(PriorityQHeap *pqh);
void insert(PriorityQHeap *pqh, int priority, void* data);

#endif