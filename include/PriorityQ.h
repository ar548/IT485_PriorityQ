#ifndef __pq__
#define __pq__

#include <stdlib.h>
#include <stdio.h>

typedef struct pq_node pq_node_t;

struct pq_node {
	pq_node_t *next;
	pq_node_t *prev;
	void* data;
	int priority;
};

typedef struct {
	pq_node_t *head;
	pq_node_t *tail;
	size_t nodeSize;
	int numNodes;
} PriorityQueue;

PriorityQueue *pq_new(size_t elementSize);
void pq_free(PriorityQueue *pq);
void *pq_delete_max(PriorityQueue *pq);
void *pq_delete_min(PriorityQueue *pq);
void pq_insert(PriorityQueue *pq, void*data, int priority);
void print_priotities(PriorityQueue *pq);
void *pq_toArray_ascending(PriorityQueue *pq);
void *pq_toArray_descending(PriorityQueue *pq);

#endif
