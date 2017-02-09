#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>

int	n=2;
int	arr[4][4] = {{112, 42, 83, 119},
			{56, 125, 56, 49},
			{15, 78, 101, 43},
			{62, 98, 114, 108}};


sum_array()
{
	int	i, j;
	int	sum=0;

	for(i=0; i < n; i++)
		for(j=0; j < n; j++)
			sum += arr[i][j];

	printf("sum=%d\n", sum);
}

void
reverse_col(int c)
{
	int	r, k;
	int	tmp;

	for (r = 0; r < n; r++) {
		k = 2*n -1 - r;
		tmp = arr[r][c]; 	
		arr[r][c] = arr[k][c];
		arr[k][c] = tmp;
	}
}

void
reverse_row(int r)
{
	int	c, k;
	int	tmp;

	for (c = 0; c < n; c++) {
		k = 2*n -1 - c;
		tmp = arr[r][c]; 	
		arr[r][c] = arr[r][k];
		arr[r][k] = tmp;
	}
}

pr_array2()
{
	int	i, j;

	for(i=0; i < 2* n; i++) {
		for(j=0; j < 2*n; j++)
			printf("%d ", arr[i][j]);

		printf("\n");
	}

	sum_array();
	printf("\n");
}

/* for each element in the sub matrix, we search for its biggest */
find_biggest()
{
	int	i, j;
	int	last;
	int	n1, n2, n3, n4;

	last = 2*n - 1;
	for(i=0; i<n; i++)
	for(j=0; j<n; j++) {
		n1 = arr[i][j];
		n2 = arr[last-i][j];
		n3 = arr[i][last-j];
		n4 = arr[last-i][last-j];

		if (n2 > n1 && n2 > n3 && n2 > n4) /* n2 is the biggest */
			reverse_row(j);

		if (n3 > n1 && n3 > n2 && n3 > n4) /* n3 is the biggest */
			reverse_row(i);

		if (n4 > n1 && n4 > n2 && n4 > n3){ /* n4 is the biggest */
			reverse_row(i);
			reverse_col(j);
		}
	}
}


main()
{
	int	i;

	pr_array2();

/*
	reverse_col(1);
	pr_array2();

	reverse_row(2);
	pr_array2();
*/

	find_biggest();
	pr_array2();
}
