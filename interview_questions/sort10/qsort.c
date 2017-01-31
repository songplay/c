/*
 *	quick sort
 */
#include <stdio.h>

/* partition the array and return the index of partition point */
int
part(int array[], int start, int end)
{
	int	middle;
	int	pivot, tmp;

	/* get the partition value */
	middle = (start + end)/2;
	pivot = array[middle];

	while (start <= end) {
		// find the ones to be swaped
		while (array[start] < pivot)
				start++;
		while (pivot < array[end])
				end--;

		if (start <= end) {	// swap
			tmp = array[start];
			array[start] = array[end];
			array[end] = tmp;
			start++;
			end--;	
		}
	}

	return	start;
}

void
qsort(int array[], int start, int end)
{
	int	m;

	m = part(array, start, end);
	if (start < m-1)
		qsort(array, start, m-1);
	if (m < end)
		qsort(array, m, end);
}


void
sort(int array[], int size)
{
	qsort(array, 0, size-1);
}
