#include "Path.h"
#include <limits.h>
#include <string.h>
#include <stdio.h>

#define get_heuristic(map, curr)		((map->end.x - curr->x)*(map->end.x - curr->x) + (map->end.y - curr->y)*(map->end.y - curr->y))


DLL_t* path_find(TileMap *map)
{
	/* initialize variables */
	DLL_t *open = DLL_new(sizeof(Vector2D));
	DLL_t *closed = DLL_new(sizeof(Vector2D));
	DLL_t *ret = DLL_new(sizeof(Vector2D));
	Vector2D *curr, *temp, v;
	int *cost = (int*)malloc(sizeof(int) * map->width * map->height);
	//int *heuristic = (int*)malloc(sizeof(int) * map->width * map->height);
	int index_temp, index_curr;
	int i, j, c;
	const int width = map->width;
	const int height = map->height;
	const int endx = map->end.x;
	const int endy = map->end.y;
	const int startx = map->start.x;
	const int starty = map->start.y;
	memset(cost, INT_MAX, sizeof(int) * map->width * map->height);		// max int for infinite
	//memset(heuristic, INT_MAX, sizeof(int) * map->width * map->height);
	DLL_insert_front(open, &(map->start));

	/*
	 * the tilemap is laid out such that:
	 *		(x, y) = y * width + x
	 */

	while(1)
	{
		if(DLL_Empty(open)){
			printf("Could not find path from start to finish.  ");
			break;
		}
		curr = (Vector2D*)DLL_pop_back(open);
		index_curr = curr->x + curr->y * width;

		// check left
		v = vector2d(curr->x-1, curr->y);
		temp = &v;
		//free(&v);
		if(temp->x < 0) { 
			/* TODO: ask DJ how the pacman case should be handled */
			// for this assignment do not even check it
		}
		else{
			if(temp->x == endx && temp->y == endy) 
			{ 
				/* return the correct array of the  */
				DLL_insert_front(ret, temp);
				while(curr->x != startx && curr->y != starty)
				{
					DLL_insert_front(ret, curr);
					index_curr = curr->x + curr->y * width;
					if( curr->x - 1 > 0 )
					{
						if(cost[index_curr] == cost[index_curr - 1] + 1)
						{
							curr->x--;	// I just know that this is going to cause an issue
							continue;
						}
					}
					if( curr->x + 1 < width )
					{
						if(cost[index_curr] == cost[index_curr + 1] + 1)
						{
							curr->x++;	// I just know that this is going to cause an issue
							continue;
						}
					}
					if( curr->y - 1 > 0 )
					{
						if(cost[index_curr] == cost[index_curr - width] + 1)
						{
							curr->y--;	// I just know that this is going to cause an issue
							continue;
						}
					}
					if( curr->y + 1 < height )
					{
						if(cost[index_curr] == cost[index_curr + width] + 1)
						{
							curr->y++;	// I just know that this is going to cause an issue
							continue;
						}
					}
				}
				return ret;
			}
			index_temp = temp->x + temp->y * width;
			if(map->map[index_temp] == 0)
			{
				if(cost[index_curr] + 1 < cost[index_temp])
				{
					cost[index_temp] = cost[index_curr] + 1;
					DLL_insert_front(open, temp);
				}
			}
		}
		//free(temp);

		// check right
		v = vector2d(curr->x-1, curr->y);
		temp = &v;
		//free(&v);
		if(temp->x > width) { 
			/* TODO: ask DJ how the pacman case should be handled */
			// for this assignment do not even check it
		}
		else{
			if(temp->x == endx && temp->y == endy) 
			{ 
				/* return the correct array of the  */
				DLL_insert_front(ret, temp);
				while(curr->x != startx && curr->y != starty)
				{
					DLL_insert_front(ret, curr);
					index_curr = curr->x + curr->y * width;
					if( curr->x - 1 > 0 )
					{
						if(cost[index_curr] == cost[index_curr - 1] + 1)
						{
							curr->x--;	// I just know that this is going to cause an issue
							continue;
						}
					}
					if( curr->x + 1 < width )
					{
						if(cost[index_curr] == cost[index_curr + 1] + 1)
						{
							curr->x++;	// I just know that this is going to cause an issue
							continue;
						}
					}
					if( curr->y - 1 > 0 )
					{
						if(cost[index_curr] == cost[index_curr - width] + 1)
						{
							curr->y--;	// I just know that this is going to cause an issue
							continue;
						}
					}
					if( curr->y + 1 < height )
					{
						if(cost[index_curr] == cost[index_curr + width] + 1)
						{
							curr->y++;	// I just know that this is going to cause an issue
							continue;
						}
					}
				}
				return ret;
			}
			index_temp = temp->x + temp->y * width;
			if(map->map[index_temp] == 0)
			{
				if(cost[index_curr] + 1 < cost[index_temp])
				{
					cost[index_temp] = cost[index_curr] + 1;
					DLL_insert_front(open, temp);
				}
			}
		}
		//free(temp);

		// check above
		v = vector2d(curr->x-1, curr->y);
		temp = &v;
		//free(&v);
		if(temp->x < 0) { 
			/* TODO: ask DJ how the pacman case should be handled */
			// for this assignment do not even check it
		}
		else{
			if(temp->x == endx && temp->y == endy) 
			{ 
				/* return the correct array of the  */
				DLL_insert_front(ret, temp);
				while(curr->x != startx && curr->y != starty)
				{
					DLL_insert_front(ret, curr);
					index_curr = curr->x + curr->y * width;
					if( curr->x - 1 > 0 )
					{
						if(cost[index_curr] == cost[index_curr - 1] + 1)
						{
							curr->x--;	// I just know that this is going to cause an issue
							continue;
						}
					}
					if( curr->x + 1 < width )
					{
						if(cost[index_curr] == cost[index_curr + 1] + 1)
						{
							curr->x++;	// I just know that this is going to cause an issue
							continue;
						}
					}
					if( curr->y - 1 > 0 )
					{
						if(cost[index_curr] == cost[index_curr - width] + 1)
						{
							curr->y--;	// I just know that this is going to cause an issue
							continue;
						}
					}
					if( curr->y + 1 < height )
					{
						if(cost[index_curr] == cost[index_curr + width] + 1)
						{
							curr->y++;	// I just know that this is going to cause an issue
							continue;
						}
					}
				}
				return ret;
			}
			index_temp = temp->x + temp->y * width;
			if(map->map[index_temp] == 0)
			{
				if(cost[index_curr] + 1 < cost[index_temp])
				{
					cost[index_temp] = cost[index_curr] + 1;
					DLL_insert_front(open, temp);
				}
			}
		}
		//free(temp);

		// check below
		v = vector2d(curr->x-1, curr->y);
		temp = &v;
		//free(&v);
		if(temp->x < 0) {
			/* TODO: ask DJ how the pacman case should be handled */
			// for this assignment do not even check it
		}
		else{
			if(temp->x == endx && temp->y == endy) 
			{ 
				/* return the correct array of the  */
				DLL_insert_front(ret, temp);
				while(curr->x != startx && curr->y != starty)
				{
					DLL_insert_front(ret, curr);
					index_curr = curr->x + curr->y * width;
					if( curr->x - 1 > 0 )
					{
						if(cost[index_curr] == cost[index_curr - 1] + 1)
						{
							curr->x--;	// I just know that this is going to cause an issue
							continue;
						}
					}
					if( curr->x + 1 < width )
					{
						if(cost[index_curr] == cost[index_curr + 1] + 1)
						{
							curr->x++;	// I just know that this is going to cause an issue
							continue;
						}
					}
					if( curr->y - 1 > 0 )
					{
						if(cost[index_curr] == cost[index_curr - width] + 1)
						{
							curr->y--;	// I just know that this is going to cause an issue
							continue;
						}
					}
					if( curr->y + 1 < height )
					{
						if(cost[index_curr] == cost[index_curr + width] + 1)
						{
							curr->y++;	// I just know that this is going to cause an issue
							continue;
						}
					}
				}
				return ret;
			}
			index_temp = temp->x + temp->y * width;
			if(map->map[index_temp] == 0)
			{
				if(cost[index_curr] + 1 < cost[index_temp])
				{
					cost[index_temp] = cost[index_curr] + 1;
					DLL_insert_front(open, temp);
				}
			}
		}
		//free(temp);


		// check the one above
			// is it an open tile
			// is it in the list
				// is the cost less than the current cost
			// add it to the list or move on as needed
		// repeat for 3 other directions


	}

	return NULL;

}
