#ifndef __HASH_MAP__
#define __HASH_MAP__

#define INITIAL_SIZE (5)
#define MAX_CHAIN_LENGTH (5)

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct hashmap_element{
	char* key;
	int inUse;
	void* data;
}hashmap_element_t;

typedef struct hash_map 
{
	hashmap_element_t * data;
	int numElements;
	int maxElements;
	size_t elementSize;
} hash_map_t;

hash_map_t * hash_new(size_t elementSize);
void * hash_insert();
void hash_insert(char * key, void * value);
void * hash_get(hash_map_t* hash, char * key);
void hash_free(hash_map_t * hash);
char* getMD5(char* key);
#endif

