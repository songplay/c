/*
 * quick sort: practice 3
 * 1/16/2017
 */
#include <stdio.h>


int
part(int a[], int l, int r)
{
	int	p;
	int	tmp;

	p = a[(l+r)/2];

	while (l <= r) {
		while (a[l] < p)
			l++;

		while (p < a[r])
			r--;

		if (l <= r) {
			tmp = a[l];
			a[l] =a[r];
			a[r] = tmp;
			l++;
			r--;
		}
	}

	return	l;
}


void
qsort(int a[], int l, int r)
{
	int	m;

	m = part(a, l, r);	// partition point
	if (l < m-1)
		qsort(a, l, m-1);
	if (m < r)
		qsort(a, m, r);
}

void
sort(int a[], int len)
{
	if (len > 1)
		qsort(a, 0, len-1);
}
