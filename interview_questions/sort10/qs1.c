/*
 *	Quick Sort, practice 2
 *	1/16/2017
 */
#include <stdio.h>


int
partition(int array[], int left, int right)
{
	int	p;
	int	tmp;

	p = array[(left+right)/2];	// pivot
	while (left <= right) {
		while (array[left] < p)
			left++;

		while (p < array[right])
			right--;

		// swap
		if (left <= right) {
			tmp = array[left];
			array[left] =array[right];
			array[right]= tmp;
			left++;
			right--;
		}
	}

	return	left;
}

void
qsort(int array[], int left, int right)
{
	int	m;

	m = partition(array, left, right);
	if (left < m-1)
		qsort(array, left, m-1);
	if (m < right)
		qsort(array, m, right);
}

void
sort(int array[], int len)
{
	if (len > 1)
		qsort(array, 0, len-1);
}
