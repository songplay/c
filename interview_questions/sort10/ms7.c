/*
 * merge sort
 */

#include <stdio.h>

void
merge(int a[], int begin, int mid, int end)
{
	int	k;
	int	current, l, r;
	int	rr;
	int	b[1024];

	//copy the array
	for(k=begin;k<=end; k++)
		b[k] = a[k];

	current = begin;
	l = begin;
	r = mid+1;
	while ((l <= mid) && (r <= end) )
		if (b[l] < b[r])
			a[current++] = b[l++];
		else
			a[current++] = b[r++];

	//copy the remaining
	rr= mid - l;
	for(k=0; k<=rr; k++)
		a[current+k] = b[l +k];
}


void
msort(int a[], int begin,  int end)
{
	int	middle;

	if (begin < end){
		middle = (begin + end)/2;
		msort(a, begin, middle);
		msort(a,  middle +1, end);
		merge(a, begin, middle, end);
	}
}

void
sort(int a[], int len)
{
	if (len >1)
		msort(a, 0, len-1);
}
