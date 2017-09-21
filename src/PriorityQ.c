
#include "simple_logger.h"
#include "PriorityQ.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int pq_isEmpty(PriorityQueue *pq) {
	if (pq->head == NULL)
		return 1;
	if (pq->tail == NULL)
		return 1;
	return 0;
}

PriorityQueue * pq_new(size_t elementSize)
{
	PriorityQueue *pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
	pq->head = NULL;
	pq->tail = NULL;
	pq->nodeSize = elementSize;
	pq->numNodes = 0;
	return pq;
}

pq_node_t * pq_node_new(void* data, int priority) {
	pq_node_t *pq_node = (pq_node_t*)malloc(sizeof(pq_node_t));
	pq_node->data = data;
	pq_node->priority = priority;
	pq_node->next = NULL;
	pq_node->prev = NULL;
	return pq_node;
}

void pq_free(PriorityQueue *pq)
{
	if (!pq_isEmpty(pq)) {
		pq_node_t *temp = NULL;
		pq_node_t *curr = pq->head;

		while (curr != NULL) {
			if (curr->data != NULL){
				slog("Warning: attempting to frsee a node that points to data. ");
			}
			temp = curr->next;
			free(curr);
			curr = temp;
		}
	}
	free(pq);
}

void *pq_delete_max(PriorityQueue *pq)
{
	void *r = NULL;
	if (pq == NULL)return NULL;
	if (pq_isEmpty(pq)) {
		slog("Error: attpemting to dequeue from an empty queue.");
		return NULL;
	}

	pq->numNodes--;
	r = pq->tail->data;

	// if there is only one node
	if (pq->tail->prev == NULL) {
		pq->tail = NULL;
		pq->head = NULL;
	}
	else {
		pq_node_t *temp = pq->tail;
		pq->tail = pq->tail->prev;
		pq->tail->next = NULL;
		free(temp);
	}

	return r;
}

void *pq_delete_min(PriorityQueue *pq)
{
	void* r = NULL;
	if (pq == NULL)return NULL;
	if (pq_isEmpty(pq)) {
		slog("Error: attpemting to dequeue from an empty queue.");
		return NULL;
	}

	pq->numNodes--;
	r = pq->head->data;

	// if there is only one node
	if (pq->head->next == NULL) {
		pq->tail = NULL;
		pq->head = NULL;
	}
	else {
		pq_node_t *temp = pq->head;
		pq->head = pq->head->next;
		pq->head->prev = NULL;
		free(temp);
	}

	return r;
}

void pq_insert(PriorityQueue *pq, void *data, int priority)
{
	pq_node_t *temp = NULL;
	pq_node_t *curr = NULL;
	if (pq == NULL)return;
	if (data == NULL)return;

	temp = pq_node_new(data, priority);
	pq->numNodes++;

	// check if the queue is empty
	if(pq_isEmpty(pq)) {
		pq->head = temp;
		pq->tail = temp;
		return;
	}

	// check priority is greater than tail->priority (the nes node will be new tail)
	if (priority >= pq->tail->priority)
	{
		pq->tail->next = temp;
		temp->prev = pq->tail;
		pq->tail = temp;
		return;
	}

	// find the first node that is greater than the node to be inserted.
	curr = pq->head;
	while (curr != NULL)
	{
		if (curr->priority >= temp->priority)
		{
			break;
		}
		curr = curr->next;
	}

	temp->prev = curr->prev;
	temp->next = curr;
	temp->next->prev = temp;
	// if the new node is the new head
	if (temp->prev != NULL) {
		temp->prev->next = temp;
	}
	else{
		pq->head = temp;
	}
}

void print_priotities(PriorityQueue *pq){
	// prints the values from greatest to least
	pq_node_t *curr;
	if(pq_isEmpty(pq))return;

	curr = pq->head;
	while(curr->next != NULL){
		printf("%i, ", curr->priority);
		curr = curr->next;
	}

	printf("%i \n", curr->priority);
}

void *pq_toArray_ascending(PriorityQueue *pq){
	void* ar = malloc(pq->nodeSize * pq->numNodes);
	int i = 0;
	pq_node_t *curr = pq->tail;
	for(i = 0; i < pq->numNodes; i++){
		memcpy( ((char *)ar + i * (pq->nodeSize) ), curr->data, pq->nodeSize );
		curr = curr->prev;
	}

	return ar;
}

void *pq_toArray_descending(PriorityQueue *pq){
	void* ar = malloc(pq->nodeSize * pq->numNodes);
	int i = 0;
	pq_node_t *curr = pq->head;
	for(i = 0; i < pq->numNodes; i++){
		memcpy( ((char *)ar + i * (pq->nodeSize) ), curr->data, pq->nodeSize );
		curr = curr->next;
	}

	return ar;
}
