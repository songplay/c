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

int
sum_row(int r, int cb, int ce)
{
	int	k;
	int	sum=0;

	for(k=cb; k<=ce; k++)
		sum += arr[r][k];

	return	sum;
}

int
sum_col(int rb, int re, int c)
{
	int	r;
	int	sum=0;

	for(r=rb; r<=re; r++)
		sum += arr[r][c];

	return	sum;
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

/*
 * compare the sum row by row from columb begin to end 
 * reverse the column if the low is bigger then the high
 */
void
bubble_up(int cb, int ce)
{
	int	c, j;
	int	sum_high, sum_low;

	for(c=cb; c<= ce; c++)
		sum_high = sum_col(0, n-1, c);
		sum_low = sum_col(n, 2*n -1, c);
		if (sum_low > sum_high) /* will reverse by columns */
				reverse_col(c);
}

/* reverse the row if the right half is bigger than the left */
void
bubble_left(int rb, int re)
{
	int	r;
	int	sum_left, sum_right;

	for(r = rb; r <=re; r++) {
		sum_left = sum_row(r, 0, n-1);
		sum_right = sum_row(r, n, 2*n-1);
		if (sum_right > sum_left)
			reverse_row(r);
	}
}


/* bubble sort */
bubble_sort()
{
	int	i;

	/* bubble from the low right to up right */
	bubble_up(0, n-1);	/* column 0 to 2n-1 */
	bubble_up(n, 2*n-1);	/* column 0 to 2n-1 */
	bubble_left(0, n-1);	/* row 0 to 2n-1 */
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

	bubble_sort();
	pr_array2();
}
