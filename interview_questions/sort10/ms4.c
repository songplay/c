#include <stdio.h>

void
merge(int a[], int begin, int middle, int end)
{
	int	k;
	int	b[1024];
	int	left, right, current;
	int	r;

	/* copy the array */
	for(k=begin; k<=end; k++)
		b[k] = a[k];

	current = begin;	// index for array a[]
	left = begin;		// index for array b[]
	right = middle+1;	// index for array b[]

	while (left <= middle && right <= end)
		if (b[left] < b[right])
			a[current++] = b[left++];
		else
			a[current++] = b[right++];

	// copy the remaining
	r = middle - left;
	for(k=0; k<=r; k++)
		a[current+k] = b[left+k];
}

void
msort(int a[], int begin, int end)
{
	int	middle;

	if (begin < end) {
		middle = (begin + end) / 2;
		msort(a, begin, middle);
		msort(a, middle+1, end);
		merge(a, begin, middle, end);
	}
}
void
sort(int a[], int len)
{
	if (len > 1)
		msort(a, 0, len-1);
}
