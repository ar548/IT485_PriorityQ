#include "priorityQ_heap.h"
#include <stdio.h>
#include <string.h>
#include "simple_logger.h"

PriorityQHeap * pqh_new(size_t elementSize){
	PriorityQHeap *pqh = (PriorityQHeap*)malloc(sizeof(PriorityQHeap));
	pqh->numElements = 0;
	pqh->maxElements = 1;
	pqh->elementSize = elementSize;
	pqh->nodes = (pqh_node_t**)malloc(1*sizeof(pqh_node_t));
	return pqh;
}

void pqh_free(PriorityQHeap *pqh);

void* pqh_delete_min(PriorityQHeap *pqh)
{
	pqh_node_t *temp = NULL;
	pqh_node_t data;
	int curr = NULL;
	

	if(pqh == NULL) return;
	if(pqh->nodes == NULL){
		slog("Error: attpemting to dequeue from an empty queue.");
		return NULL;
	}

	data = *(pqh->nodes[0]);	// the container of the value to return
	
	pqh->nodes[0] = pqh->nodes[pqh->numElements-1];	// move the last element to the head
	pqh->nodes[pqh->numElements] = NULL;			// set the last element to NULL
	pqh->numElements--;

	curr = 0;
	while( 
		(
			curr*2+2 < pqh->numElements
		) && (
			pqh->nodes[curr]->priority > pqh->nodes[curr * 2 + 1]->priority  || 
			pqh->nodes[curr]->priority > pqh->nodes[curr * 2 + 2]->priority
		) 
	)
	{
		// swap curr with its least child
		if(pqh->nodes[curr * 2 + 1]->priority <= pqh->nodes[curr * 2 + 2]->priority)
		{
			temp = pqh->nodes[curr];
			pqh->nodes[curr] = pqh->nodes[curr * 2 + 1];
			pqh->nodes[curr * 2 + 1] = temp;
			curr = curr*2+1;
			temp = NULL;
		}
		else
		{
			temp = pqh->nodes[curr];
			pqh->nodes[curr] = pqh->nodes[curr * 2 + 2];
			pqh->nodes[curr * 2 + 2] = temp;
			curr = curr*2+2;
			temp = NULL;
		}
	}

	if(pqh->numElements < (pqh->maxElements)/2 - 1)
	{
		pqh->maxElements = pqh->maxElements/2 - 1;
		pqh->nodes = (pqh_node_t**)realloc(pqh->nodes, pqh->maxElements*sizeof(pqh_node_t));
	}

	return data.data;
}

void pqh_insert(PriorityQHeap *pqh, void* data, int priority){
	pqh_node_t *temp;
	pqh_node_t *temp2 = NULL;
	int curr = NULL;


	if(pqh == NULL) return;

	if(pqh->numElements == pqh->maxElements)
	{
		pqh->maxElements += pqh->maxElements + 1;
		pqh->nodes = (pqh_node_t**)realloc(pqh->nodes, pqh->maxElements*sizeof(pqh_node_t));
	}

	temp = (pqh_node_t*)malloc(sizeof(pqh_node_t));
	temp->data = data;
	temp->priority = priority;

	pqh->nodes[pqh->numElements] = temp;
	pqh->numElements++;

	curr = pqh->numElements-1;
	while(pqh->nodes[curr]->priority < pqh->nodes[(curr-1)/2]->priority && curr != 0)
	{	
		// swap the two elements
		temp2 = pqh->nodes[curr];
		pqh->nodes[curr] = pqh->nodes[(curr-1)/2];
		pqh->nodes[(curr-1)/2] = temp2;
		temp = NULL;

		// reassign curr and repeat
		curr = (curr-1)/2;
	}
}

void pqh_print_nodes(PriorityQHeap *pqh)
{
	int i = 0;
	if(pqh ==  NULL) return;
	for(i = 0; i < pqh->numElements-1; i++)
	{
		printf("%s, ", pqh->nodes[i]->data);
	}
	printf("%s \n", pqh->nodes[pqh->numElements-1]->data);
}

// left child: 2*n + 1
// right child: 2*n + 2
// parent = (n-1)/2