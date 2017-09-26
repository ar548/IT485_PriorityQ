#ifndef __ksort__
#define __ksort__

/**
 * @brief finds the pos th element of an array (0 based)
 * @param a is the pointer to the array that we are searching
 * @param numElem is the number of elements in the array
 * @param pos is the integer position of the element that you are looking for
 * @note this will assuem that the array is being repeatedly ksorted and will 
	take that into account by starting with the nth element in the array. 
 */
int ksort(int *a, int numElem, int pos);

#endif