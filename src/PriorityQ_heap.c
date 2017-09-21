#include "priorityQ_heap.h"
#include <stdio.h>
#include <string.h>

PriorityQHeap * pqh_new(size_t elementSize){
	PriorityQHeap *pqh = (PriorityQHeap*)malloc(sizeof(PriorityQHeap));
	pqh->numElements = 0;
	pqh->maxElements = 1;
	pqh->elementSize = elementSize;
	pqh->nodes = (pqh_node_t**)malloc(1*sizeof(pqh_node_t));
	return pqh;
}

void pqh_free(PriorityQHeap *pqh);

void* pqh_delete_max(PriorityQHeap *pqh);

void pqh_insert(PriorityQHeap *pqh, void* data, int priority){
	pqh_node_t *temp;
	int curr = NULL;
	pqh_node_t *temp2 = NULL;


	if(pqh == NULL) return;

	if(pqh->numElements == pqh->maxElements){
		pqh->maxElements += pqh->maxElements + 1;
		/*
		temp = (pqh_node_t*)malloc(pqh->numElements * sizeof(pqh_node_t));
		memcpy(temp, pqh->nodes, pqh->numElements*sizeof(pqh_node_t));
		
		free(pqh->nodes);
		pqh->nodes = NULL;

		pqh->nodes = (pqh_node_t*)malloc(pqh->maxElements * sizeof(pqh_node_t));
		memcpy(pqh->nodes, temp, pqh->numElements*sizeof(pqh_node_t));
		free(temp);
		temp = NULL;
		*/

		pqh->nodes = (pqh_node_t**)realloc(pqh->nodes, pqh->maxElements*sizeof(pqh_node_t));
	}

	temp = (pqh_node_t*)malloc(sizeof(pqh_node_t));
	temp->data = data;
	temp->priority = priority;

	pqh->nodes[pqh->numElements++] = temp;

	curr = pqh->numElements-1;
	while(pqh->nodes[curr]->priority < pqh->nodes[(curr-1)/2]->priority && curr != 0){
		
		// swap the two elements
		temp2 = pqh->nodes[curr];
		pqh->nodes[curr] = pqh->nodes[(curr-1)/2];
		pqh->nodes[(curr-1)/2] = temp2;

		// reassign curr and repeat
		curr = (curr-1)/2;
	}
}

void pqh_print_nodes(PriorityQHeap *pqh){
	int i = 0;
	if(pqh ==  NULL) return;
	for(i = 0; i < pqh->numElements-1; i++){
		printf("%s, ", pqh->nodes[i]->data);
	}
	printf("%s \n", pqh->nodes[pqh->numElements-1]->data);
}