#include <stdio.h>
#include <stdlib.h>

void
merge(int a[], int begin, int middle, int end)
{
	int	*b;
	int	*p;
	int	k, remaining;
	int	current, right, left;
	int	size;

	if (begin == end)
		return;

	if (end > 0) {
		size = sizeof(int) * (end + 1);
		b = (int *) malloc(size);
	} else
		return;

	/* copy to buffer b */
	p = b + begin;
	for(k=begin; k<=end; k++)
		*p++ = a[k];

	current = begin;
	left = begin;
	right = middle + 1;
	p = b;
	while (left <= middle && right <= end) 
		if ( *(p+left) < *(p+right) )
			a[current++] = *(p + left++);
		else
			a[current++] = *(p + right++);

	remaining = middle - left;
	for (k=0; k<= remaining; k++)
		a[current + k] = *(p + left + k);

	free(b);
}

void
msort(int a[], int begin,int end)
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
		msort(a, 0, len -1);
}
