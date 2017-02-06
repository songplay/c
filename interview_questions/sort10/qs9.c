#include <stdio.h>

int
partition(int a[], int left, int right)
{
	int	pivot;
	int	tmp;

	pivot = a[(left+right)/2];

	while (left <= right) {
		if (a[left] < pivot)
			left++;

		if (pivot < a[right])
			right--;

		if (left <= right) {
			tmp = a[left];
			a[left] = a[right];
			a[right] = tmp;
			left++;
			right--;
		}
	}

	return	left;
}


void
qsort(int a[], int begin, int end)
{
	int	m;

	if (begin < end){
		m = partition(a, begin, end);

		if (begin < m-1)
			qsort(a, begin, m-1);

		if (m < end)
			qsort(a, m, end);
	}
}

void
sort(int a[], int len)
{
	if (len > 1)
		qsort(a, 0, len-1);
}
