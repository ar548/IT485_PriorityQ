#include "HashMap.h"

hash_map_t * hash_new(size_t elementSize)
{
	hash_map_t * hash = (hash_map_t*)malloc(sizeof(hash_map_t));
	hash->data = (hashmap_element_t*)malloc(5*sizeof(hashmap_element_t));
	hash->numElements = 0;
	hash->maxElements = INITIAL_SIZE;
	hash->elementSize = elementSize;
}

void * hash_insert()
{

}

void hash_insert(char * key, void * value)
{

}

void * hash_get(hash_map_t* hash, char * key)
{

}

void hash_free(hash_map_t * hash)
{

}

char* getMD5(char* key){

}