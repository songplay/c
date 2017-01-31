/*
 * main.c    Sort test program
 */
#include <stdio.h>


/* print the array */
void
pr_array(int	array[], int len)
{
	int	k;

	for(k=0; k< len; k++)
		printf("%d, ", array[k]);

	printf("\n");
}

main()
{
	// int	array[]= {10, 111, 52, 333, 2, 200, 55, 22, 1, 3};
	int	array[]= {10, -111, -52, 333, -2, 200, 55, 22, 1, 3};
	// int	array[]= {3};
	int	size;
	extern void sort();

	size = sizeof(array)/ sizeof(int);
	printf("size=%d\n", size);

	pr_array(array, size);
	sort(array, size);
	pr_array(array, size);
}
