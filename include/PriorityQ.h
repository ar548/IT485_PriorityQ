#ifndef __PQ__
#define __PQ__

typedef struct
{
	// more of my stuff goes here
	pq_node_t* nodes;
	int numElements;
	int maxElements;
	size_t nodeSize;
}PriorityQueue;

typedef struct{
	void* data;	// size of elementSize
	int priority;
}pq_node_t;



PriorityQueue * pq_new(size_t elementSize);
void pq_delete(PriorityQueue *pq);
void *pq_delete_max(PriorityQueue *pq);
void *pq_delete_min(PriorityQueue *pq);
void pq_insert(PriorityQueue *pq, void *data, int priority);



/**
 * Im thinking that the best way to do this without knowing anything else about the data
 * is to do it with a binary heap (max).  
 */

#endif