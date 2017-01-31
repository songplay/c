/*
 * quick sort: 4
 */
#include <stdio.h>

/* partition */
int
part(int a[], int begin, int end)
{
	int	pivot;
	int	tmp;

	pivot = a[(begin+end)/2];

	while (begin <= end){
		while (a[begin] < pivot)
			begin++;
		while (pivot < a[end])
			end--;

		// now swap
		tmp = a[begin];
		a[begin] = a[end];
		a[end] = tmp;
		begin++;
		end--;
	}
	return	begin;
}


/* quick sort */
void
qsort(int a[], int begin, int end)
{
	int	m;

	if (begin < end) {
		m = part(a, begin, end);
		qsort(a, begin, m-1);
		qsort(a, m, end);
	}
}

void
sort(int a[], int len)
{
	if (len > 1)
		qsort(a, 0, len-1);
}
