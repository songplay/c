/*
 * Find the smallest diff : sort and iteriate
 * 2/6/2017
 */
#include	<stdio.h>
#include		<stdlib.h>

void
pr_array(int a[], int alen)
{
	int	k;

	for(k=0; k<alen; k++)
		printf("%d,", a[k]);

	printf("\n");
}

int
partition(int a[], int left, int right)
{
	int	pivot;
	int	tmp;

	pivot = a[(left+right)/2];

	while (left <= right) {
		while (a[left] < pivot)
			left++;
		while (pivot < a[right])
			right--;

		/* swap */
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
msort(int a[], int begin, int end)
{
	int	m;

	if (begin < end) {
		m = partition(a, begin, end);
		if (begin < m-1)
			msort(a, begin, m-1);
		if (m < end)
			msort(a, m, end);
	}
}

int
findSmallest(int a[], int alen, int b[], int blen)
{
	int	k, j;
	int	s;
	int	ss;
	int	diff;

	/* first sort both a and b */
	msort(a, 0, alen -1);
	pr_array(a, alen);

	msort(b, 0, blen -1);
	pr_array(b, blen);

	/* for each in array a, find the smallest diff */
	s = abs(a[0] - b[0]);
	for(k=0; k<alen; k++) {
		ss = abs(a[k] - b[0]);
		for(j=0; j<blen; j++) {
			diff = abs(a[k] - b[j]);
			if (s > diff)
				s = diff;	

			if (ss > diff)
				ss = diff;
			else
				break;
		}
	}
	
	return	s;
}

main()
{
	int	a[]={1, 3, 15, 11, 2};
	int	b[]={23, 127, 235, 19, 9, 200};
	int	s;

	s = findSmallest(a, 5, b, 6);
	printf("smallest=%d\n", s);
}
