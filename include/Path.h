#ifndef __PATH__
#define __PATH__

#include "gf2d_vector.h"
#include "tilemap.h"
#include "LinkedList.h"

/*
 * @brief getes the path from the map->start to map->end if one is available by using A* herustic of cost to get to current position + distance between the points squared (the dist squared it to make it more depth firsty)
 */
DLL_t* path_find(TileMap *map);

#endif