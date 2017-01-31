/*
 * find a magic index in a sorted array
 */
#include <stdio.h>


void
magic(int array[], int start, int end)
{
	int	half;

	if (start >= end)
		return;

	half = start + (end - start)/2 ;
	if (array[half] == half)
		printf("Magic Index: %d\n", half);
	else if (array[half] > half)
		magic(array, start, half-1);
	else
		magic(array, half+1, end);
}

main()
{

}
