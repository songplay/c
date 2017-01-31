/*
 * Bubble sort
 * 1/17/2017
 */
#include <stdio.h>

void
bsort(int a[], int len)
{
	int	i, j;
	int	swap;

	for(i=0; i<len-1; i++)
	for(j=0; j<len-1-i; j++)
		if (a[j] > a[j+1]){ //swap
#ifdef	OPTION1
			swap = a[j+1];
			a[j+1] =a[j];
			a[j] = swap;
#else
			a[j] = a[j] + a[j+1];
			a[j+1] = a[j] - a[j+1];
			a[j] = a[j] - a[j+1];
#endif
		}
}

void
sort(int a[], int len)
{
	if (len > 1)
		bsort(a, len);
}
