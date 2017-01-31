/*
 * Merge Sort
 */
#include <stdio.h>
#include <stdlib.h>

/* now merge the two sorted array */
void
merge(int array[], int my[], int start, int middle, int end)
{
	int	i;
	int	left, right;
	int	current;
	int	remaining;

	/* copy the array to working array */
	for(i=start; i<= end; i++)
		my[i]= array[i];

	current = start;	/* index for array */

	/* index for working array */
	left = start;		// index for left half
	right = middle + 1;	// index for right half

	while (left <= middle &&  right <= end) {
		if (my[left] <= my[right]) {
			array[current++] =my[left++];
		}else {
			array[current++] =my[right++];
		}
	}

	/* copy the remaining */
	remaining = middle - left;
	for (i=0; i<= remaining; i++)
		array[current+i] =my[left+i];
}

void
merge_sort(int array[], int my[], int start, int end)
{
	int	middle;

	if (start < end) {
		middle = (start + end)/2;
		merge_sort(array, my, start, middle);
		merge_sort(array, my, middle+1, end);

		/* now merge the two sorted array */
		merge(array, my, start, middle, end);
	}
}

void
sort(int array[], int len)
{
	int	*my;	/* my working array */

	if (len < 2)
		return;
	else {
		my = malloc(len * sizeof(int));
		merge_sort(array, my, 0, len-1);
	}
}

