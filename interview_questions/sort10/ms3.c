/*
 * Merge Sort, pactice 3
 * 1/18/2017
 */
#include <stdio.h>


/* Merge the two sorted */
void
merge(int a[], int start, int middle, int end)
{
	int	k;
	int	remaining;
	int	left, right, current;
	int	help[100];

	/* copy over the array */
	for(k=start; k<=end; k++)
		help[k] =  a[k];

	current = start;
	left = start;
	right = middle+1;

	while (left <= middle && right <= end)
		if (help[left] < help[right])
			a[current++] = help[left++];
		else
			a[current++] = help[right++];

	/* copy the remaining */
	remaining = middle - left;

	for(k=0; k<= remaining; k++)
		a[current+k] = help[left + k];
}

void
msort(int a[], int start, int end)
{
	int	middle;

	if (start < end) {
		middle = (start + end) / 2;

		msort(a, start, middle);
		msort(a, middle+1, end);

		merge(a, start, middle, end);
	}	
}

void
sort(int a[], int len)
{
	if (len > 1)
		msort(a, 0, len-1);
}
