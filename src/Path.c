#include "Path.h"
#include <limits.h>
#include <string.h>

DLL_t* path_find(TileMap *map)
{
	/* initialize variables */
	DLL_t *open = DLL_new(sizeof(Vector2D));
	DLL_t *closed = DLL_new(sizeof(Vector2D));
	Vector2D *curr;
	int *cost = (int*)malloc(sizeof(int) * map->width * map->height);	
	int index;
	
	
	memset(cost, INT_MAX, sizeof(int) * map->width * map->height);		// max int for infinite
	


}
