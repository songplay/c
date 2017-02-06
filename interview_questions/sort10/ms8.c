/*
 * merge sort: lab 8
 * 2/5
 */
#include <stdio.h>

void
merge(int a[], int begin, int middle, int end)
{
	int	b[1024];
	int	k;
	int	current, left, right;
	int	remaining;

	/* copy array a to b */
	for (k=begin; k <= end; k++)
		b[k] =a[k];

	/* merge */
	current = begin;
	left = begin;
	right = middle + 1;

	while (left <= middle && right <= end) {
		if (b[left] < b[right])
			a[current++] = b[left++];
		else
			a[current++] = b[right++];

	}

	/* copy the remaining */
	remaining = middle - left;
	for(k=0; k <= remaining; k++)
		a[current + k] = b[left + k];

}


void
msort(int a[], int begin, int end)
{
	int	m;

	if (begin < end) {
		m = (begin + end) /2;

		msort(a, begin, m);
		msort(a, m+1, end);
		merge(a, begin, m, end);
	}
}

void
sort(int a[], int len)
{
	if (len > 1)
		msort(a, 0, len - 1);
}
