/*
 * find an element in a rotated array
 * 1/22/17
 */
#include <stdio.h>
#include <stdbool.h>

/* return the index if found, return -1 if not found */
int
search1(int a[], int len, int d)
{
	int	k;
	bool	rotated=false;

	for(k=0; k<len; k+=2){
		if (a[k] == d)
			return	k;

		if (a[k+1] == d)
			return	k+1;

		if (a[0] > a[k])	// hit the rotated point
			rotated = true;

		if (rotated && ((a[0] == a[k]) || a[0] == a[k+1]))
			return	-1;
	}

	return	-1;
}

/* return the index if found, return -1 if not found */
int
search(int a[], int len, int d)
{
	int	k;
	bool	rotated=false;

	for(k=0; k<len; k++) {
		if (a[k] == d)
			return	k;
		else if (a[0] > a[k])	// hit the rotated point
			rotated = true;

		if (rotated && (a[0] == a[k]))
			return	-1;
	}

	return	-1;
}

void
pr_array(int a[], int len)
{
	int	k;

	for(k=0; k < len; k++)
		printf("%d, ", a[k]);

	printf("\n");
}


main()
{
	int	a[]={15,16,19, 1, 3, 4, 7, 15, 16, 19, 1, 3,4};
	int	t = 4;

	pr_array(a, 13);
	printf("d=%d, index=%d\n", t, search1(a, 13, t));
}
