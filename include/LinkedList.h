#ifndef __LinkedList__
#define __LinkedList__

typedef struct DLL_node DLL_node_t;
typedef struct DLL DLL_t;

struct DLL{
	DLL_node_t *head;
	DLL_node_t *tail;
	int length;
	size_t nodeSize;
};

struct DLL_node{
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


void DLL_insert_front(DLL_t *DLL, void* data);
void DLL_insert_back(DLL_t *DLL, void* data);
void DLL_print_forward(DLL_t *DLL);
void DLL_print_backward(DLL_t *DLL);

void* DLL_pop_front(DLL_t *DLL);
void* DLL_pop_back(DLL_t *DLL);
void* DLL_to_array_forward(DLL_t *DLL);
void* DLL_to_array_backward(DLL_t *DLL);

/**
 * @brief check if the DLL is empty
 */
int DLL_Empty(DLL_t *DLL);

#endif