#ifndef __PQH__
#define __PQH__

#include <stdlib.h>
typedef struct pqh_node pqh_node_t;

struct pqh_node{
	int priority;
	void *data;
};

typedef struct {
	size_t elementSize;
	int numElements;
	int maxElements;
	pqh_node_t **nodes;
} PriorityQHeap;

PriorityQHeap * pqh_new(size_t elementSize);
void pqh_free(PriorityQHeap *pqh);
void* pqh_delete_min(PriorityQHeap *pqh);
void pqh_insert(PriorityQHeap *pqh, void* data, int priority);
void pqh_print_nodes(PriorityQHeap *pqh);

#endif