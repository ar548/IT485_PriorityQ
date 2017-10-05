#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

DLL_t* DLL_new(size_t elementSize){
	DLL_t *DLL = (DLL_t*)malloc(sizeof(DLL_t));
	if(!DLL){
		printf("Error: could not allocate space for this DLL_t.  \n");
		printf("\tsizeof(DLL_t) : %i", sizeof(DLL_t)); 
		return NULL;
	}
	DLL->nodeSize = elementSize;
	DLL->length = 0;
	DLL->head = NULL;
	DLL->tail = NULL;
}

DLL_node_t *DLL_new_node(void* data){
	
	if(data == NULL){
		printf("Error: attempting to create a node with NULL data.  \n");
		return NULL;
	}

	DLL_node_t * node = (DLL_node_t*)malloc(sizeof(DLL_node_t));
	if(!node){
		printf("Error: could not allocate space for this DLL_node_t.  \n");
		printf("\tsizeof(DLL_node_t) : %i", sizeof(DLL_node_t)); 
		return NULL;
	}
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
}


void DLL_insert_front(DLL_t *DLL, void* data){
	
	DLL_node_t *temp;

	if(DLL == NULL){
		printf("Error: attempting to insert to an empty DLL.  \n");
		return;
	}
	if(data == NULL){
		printf("Error: attempting to insert NULL data.  \n");
		return;
	}

	temp = DLL_new_node(data);
	if(!temp){
		return;
	}

	if(DLL_Empty(DLL)){
		DLL->head = temp;
		DLL->tail = temp;
		return;
	}

	temp->next = DLL->head;
	DLL->head->prev = temp;
	DLL->head = temp;
}


void DLL_insert_back(DLL_t *DLL, void* data){
	DLL_node_t *temp;

	if(DLL == NULL){
		printf("Error: attempting to insert to an empty DLL.  \n");
		return;
	}
	if(data == NULL){
		printf("Error: attempting to insert NULL data.  \n");
		return;
	}

	temp = DLL_new_node(data);
	if(!temp){
		return;
	}

	if(DLL_Empty(DLL)){
		DLL->head = temp;
		DLL->tail = temp;
		return;
	}

	temp->prev = DLL->tail;
	DLL->tail->prev = temp;
	DLL->tail = temp;
}

void DLL_print_forward(DLL_t *DLL){
	DLL_node_t *curr;
	if(DLL_Empty(DLL)) return;

	curr = DLL->head;
	while(curr->next != NULL){
		printf("%S, ", curr->data);
		curr = curr->next;
	}

	printf("%s \n", curr->data);
}

void DLL_print_backward(DLL_t *DLL){
	DLL_node_t *curr;
	if(DLL_Empty(DLL)) return;

	curr = DLL->tail;
	while(curr->prev != NULL){
		printf("%S, ", curr->data);
		curr = curr->prev;
	}

	printf("%s \n", curr->data);
}


void* DLL_pop_front(DLL_t *DLL);
void* DLL_pop_back(DLL_t *DLL);
void* DLL_to_array_forward(DLL_t *DLL);
void* DLL_to_array_backward(DLL_t *DLL);

int DLL_Empty(DLL_t *DLL){
	if(DLL->head == NULL || DLL->tail == NULL) 
		return 1;
	return 0;
}