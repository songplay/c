/*
 * Merge two sorted array a and b into a
 * 1/20/2017
 */
#include <stdio.h>

void
pr_array(int a[], int len)
{
	int k;

	for(k=0; k<len; k++)
		printf("%d, ", a[k]);

	printf("\n");
}


main()
{
	int	a[100]={1,3,5,7};
	int	b[]={-5, 2,4,6, 77};


	merge(a, 4, b, 5);
	pr_array(a, 9);
}
