/*
 * Binary search
 * 1/20/2017
 */
#include <stdio.h>

int
bsearch(int a[], int low, int high, int t)
{
	int	middle;

	if (low < high) {
		middle = (high+low)/2;
		
		if (t < a[middle])
			bsearch(a, low, middle - 1, t);
		else if (t > a[middle])
			bsearch(a, middle+1, high, t);
		else
			return	middle;
	}
}
