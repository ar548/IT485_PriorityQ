#include "K_sort.h"
#include <stdio.h>

int ksort(int *a, int numElem, int pos)
{
	if(a == NULL)return -0;
	if(pos>numElem-1){
		printf("Error: attempting to find a number outside the range of the array");
		return -0;
	}
	return ksort_helper(a, numElem, pos, 0, numElem-1);
}

int ksort_helper(int *a, int numElem, int pos, int start, int end){
	int i = 1;
	int temp = 0;
	//int numGreater = 0;
	//int numLess = 0;
	int curr = start;

	if(a == NULL)
	{
		printf("Error: attempting to ksort an empty list");
		return -0;
	}

	// swap pos and a[0]
	temp = a[0];
	a[0] = a[pos];
	a[pos] = temp;

	for(i = start + 1; i < end-1; i++)
	{
		if(a[curr] <= a[i])
		{
			//numGreater++;
		}
		else
		{
			temp = a[curr];
			a[curr] = a[i];
			a[i] =  a[curr+1];
			a[curr+1] = temp;
			curr++;
			//numLess++;
		}
	}

	if(curr == pos)
	{
		return a[pos];
	}
	if(curr > pos)
	{
		return ksort_helper(a, numElem, pos, start, curr);
	}
	if(curr < pos)
	{
		return ksort_helper(a, numElem, pos, curr, end);
	}
	return 0;	//unreachable statement
}

