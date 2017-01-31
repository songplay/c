/*
 *	Merge Sort, practice 2
 *	1/16/2017
 */
#include <stdio.h>
#include <stdlib.h>

void
Merge(int array[], int tmp[], int start, int middle, int end)
{
	int	k;
	int	current, left, right;
	int	remaining;

	/* copy to the tmp array */
	for(k=start; k<=end; k++)
		tmp[k] = array[k];

	current = start;	// index for array
	left =start;		// index for left half, array tmp
	right = middle+1;	// index for right half, array tmp

	while (left <= middle && right <= end)
		if (tmp[left] <= tmp[right])
			array[current++] = tmp[left++];
		else
			array[current++] = tmp[right++];

	/* copy the remaining */
	remaining = middle - left;
	for(k=0; k<=remaining; k++)
		array[current+k] = tmp[left+k];
}

void
MergeSort(int array[], int tmp[], int start, int end)
{
	int	middle;

	if (start < end) {
		middle = (start + end) / 2;
		MergeSort(array, tmp, start, middle);
		MergeSort(array, tmp, middle+1, end);

		/* merge the two sort arrays */
		Merge(array, tmp, start, middle, end);
	}
}

void
sort(int array[], int size)
{
	int	*tmp;

	if (size < 2)	// no need to sort
		return;
	else {
		tmp = malloc(sizeof(int) * size);
		MergeSort(array, tmp, 0, size -1);
		free(tmp);
	}
}
