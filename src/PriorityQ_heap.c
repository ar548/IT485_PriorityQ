#include "priorityQ_heap.h"

PriorityQHeap * pqh_new(size_t elementSize);
void pqh_free(PriorityQHeap *pqh);
void* pqh_delete_max(PriorityQHeap *pqh);
void insert(PriorityQHeap *pqh, int priority, void* data);