/*
 * Merge Sort: 6
 * 1/19/2017
 */
#include <stdio.h>


/* merge the two sorted */
void
merge(int a[], int begin, int middle, int end)
{
	int	k;
	int	b[1000];
	int	left, right, current;
	int	remaining;

	/* copy the array */
	for(k=begin; k<=end; k++)
		b[k] = a[k];

	current = begin;
	left = begin;
	right =middle+1;

	while (left <= middle && right <= end)
		if (b[left] < b[right])
			a[current++] = b[left++];
		else
			a[current++] = b[right++];
	
	/* copy the remaining */
	remaining = middle - left;
	for(k=0; k<=remaining; k++)
		a[current+k] = b[left + k];
}


void
msort(int a[], int begin, int end)
{
	int	middle;

	if (begin < end) {
		middle = (begin+end)/2;
		msort(a, begin, middle);
		msort(a, middle+1, end);
	
		merge(a, begin, middle, end);
	}
}

void 
sort(int a[], int len)
{
	if (len > 1)
		msort(a, 0, len -1);
}
