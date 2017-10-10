#ifndef __LinkedList__
#define __LinkedList__

#include <stdlib.h>

typedef struct DLL_node DLL_node_t;
typedef struct DLL DLL_t;

/**
 * @var head: the head of the DLL.
 * @var tail: the tail of the DLL.
 * @var length: the length of the DLL (number of nodes).
 * @var nodeSize: the size of the data being stored .
 */
struct DLL{
	DLL_node_t *head;
	DLL_node_t *tail;
	int length;
	size_t nodeSize;
};

/**
 * @var next: the node after this one in the list.  NULL if this is the tail.  
 * @var prev: the node before this one in the list.  NULL if this is the head.
 * @var data: a void pointer to the data being stored in this node of the DLL.
 */
typedef struct DLL_node{
	DLL_node_t *next;
	DLL_node_t *prev;
	void *data;
};

/**
 * @brief allocate and instantiate a new DLL
 * @param elementSize is the size of the data structure being stored in this DLL
 */
DLL_t* DLL_new(size_t elementSize);

/**
 * @brief allocate and instantiate a new DLL_node_t
 * @param data is a pointer to the data structure being stored in this DLL_node
 */
DLL_node_t *DLL_new_node(void* data);

/**
 * @brief Insert data at the front of DLL
 * @param DLL is the  DLL to be inserted to 
 * @param data is the pointer to the data being inserted.
 */
void DLL_insert_front(DLL_t *DLL, void* data);

/**
 * @brief Insert data at the back of DLL
 * @param DLL is the  DLL to be inserted to 
 * @param data is the pointer to the data being inserted.
 */
void DLL_insert_back(DLL_t *DLL, void* data);

/**
 * @brief print the DLL starting at the head
 * @param DLL is the  DLL to be printed 
 */
void DLL_print_forward(DLL_t *DLL);

/**
 * @brief print the DLL starting at the head
 * @param DLL is the  DLL to be printed 
 */
void DLL_print_backward(DLL_t *DLL);

/**
 * @brief pop the first element off of the list and return its data
 * @param the DLL to remove the first element of
 */
void* DLL_pop_front(DLL_t *DLL);

/**
 * @brief pop the last element off of the list and return its data
 * @param the DLL to remove the first element of
 */
void* DLL_pop_back(DLL_t *DLL);


void* DLL_to_array_forward(DLL_t *DLL);
void* DLL_to_array_backward(DLL_t *DLL);

/**
 * @brief check if the DLL is empty
 */
int DLL_Empty(DLL_t *DLL);

#endif