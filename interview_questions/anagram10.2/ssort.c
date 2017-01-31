/*
 * sort a string so that the char are  in order of ascii value *
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

int
partition(char a[], int l, int r)
{
	char	pivot;
	char	tmp;

	pivot = a[(l+r)/2];
	while (l <= r) {
		while (a[l] < pivot)
			l++;
		while (pivot < a[r])
			r--;
			
		// swap
		if (l <= r) {
		tmp = a[l];
		a[l] = a[r];
		a[r] = tmp;
		l++;
		r--;
		}
	}

	return	l;
}

void
qsort(char a[], int l, int r)
{
	int	m;

	if (l < r) {
		m = partition(a, l, r);
		if (l < m-1)
			qsort(a, l, m-1);
		if (m < r)
			qsort(a, m, r);
	}
}

void
ssort(char a[])
{
	int	len;

	if (a != NULL){
		len = strlen(a);
		qsort(a, 0, len-1);
	}
}

void
pr_array(char *a[], int len)
{
	int	k;

	for(k=0; k<len; k++)
		printf("%s, ", a[k]);

	printf("\n");
}

main()
{
	char	msg[] = "Hello World";

	printf("%s \n", msg);
	ssort(msg);
	printf("%s \n", msg);
}
