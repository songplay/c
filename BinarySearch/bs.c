/*
 *	Binary search the smallest on a sorted array
 *	12/28/2016
 */
#include <stdio.h>

bs(int data[], int size)
{
	int	half;
	int	smallest;
	int	k;

	for(k=0; k<size; k++)
		printf("%d, ", data[k]);
	printf("\n");

	if (size == 0)
		return	-1;

	if (size == 1)
		return data[0];

	if (size == 2)
		if (data[1] > data[0])
			return	data[0];
		else	
			return	data[1];

	half = size / 2;
	printf("half=%d, data[%d]=%d\n", half, half, data[half]);

	if (data[0] < data[half-1] && data[half] < data[size-1])
		if (data[0] < data[half])
			return	data[0];
		else
			return	data[half];

	if (data[0] < data[half-1] && data[half] > data[size-1])	// the smallest is at the last half
		return	bs(&(data[half]), half);
	else
		return	bs(&(data[0]), half);
}

main()
{
	int	data1[]= {10, 12, 22, 25, 1, 5, 5, 6};
	int	data2[]= {10, 12, 25, 2, 5, 5, 6};
	int	data3[]= {10, 12, 25, 27, 33, 37, 2, 5, 5, 6};

	printf("smallest= %d\n", bs(data3, 10));
}
