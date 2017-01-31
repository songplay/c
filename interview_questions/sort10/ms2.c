/*
 * merge sort, practice 3
 *
 */
#include <stdio.h>
#include <stdlib.h>

void
merge(int a[], int b[], int start, int middle, int end)
{
	int	k;
	int	remaining;
	int	left, right, current;

	/* copy the array */
	for (k=start; k<=end; k++)
		b[k] =a[k];

	left = start;
	right = middle+1;
	current = start;

	while (left <= middle && right <= end)
		if (b[left] < b[right])
			a[current++] = b[left++];
		else
			a[current++] = b[right++];

	/* copy the remaining */
	remaining = middle - left;
	for (k=0; k<=remaining;k++)
		a[current + k] = b[left+k];
}


void
msort(int a[], int b[], int start, int end)
{
	int	middle;

	if (start < end){
		middle = (start + end)/2;
		msort(a, b, start, middle);
		msort(a, b, middle+1, end);
		merge(a, b, start, middle, end);
	}
}

void
sort(int a[], int len)
{
	int	*b;

	if (len > 1) {
		b = malloc(sizeof(int) * len);
		msort(a, b, 0, len-1);		
	}
}
