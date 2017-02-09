#include <stdio.h>
#include <stdlib.h>

#define	MAX	64

void
merge(int a[], int begin, int middle, int end)
{
	int	b[MAX];
	int	k;
	int	current, left, right;
	int	remaining;
	
	if (end >= MAX) {
		fprintf(stderr, "array is too big: end=%d\n", end);
		exit(-1);
	}

	/* 1. copy a to b */
	for(k=begin; k<=end;k++)
		b[k] = a[k];

	current = begin;
	left = begin;
	right = middle+1;

	/* 2. sort */
	while (left <= middle && right <= end)
		if (b[left] < b[right])
			a[current++] = b[left++];
		else
			a[current++] = b[right++];

	/* 3. copy the remaining */
	remaining = middle - left;
	for(k=0; k<= remaining; k++)
		a[current+k]= b[left+k];
}




void
msort(int a[], int begin, int end)
{
	int	middle;

	if (begin < end){
		middle =(begin+end)/2;
		msort(a, begin, middle);
		msort(a, middle+1, end);
		merge(a, begin,middle, end);
	}
}


void
sort(int a[], int len)
{
	if (len > 1)
		msort(a, 0, len -1);
}
