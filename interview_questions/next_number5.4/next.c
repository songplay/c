#include <stdio.h>

int
nextSmall(int x, int n)
{
	int	k;
	int	size= 8* sizeof(int);
	int	bit;
	int	mask;


	/* find the highest bit 0 */
	for(k=0; k < size; k++)
		if (((x >> k & 0x1) == 0) && ((x>>(k+1) & 0x1) == 1))
			break;

	bit = 0x1 << (k+1);
	mask = ~bit;
	x = x & mask;	// mask off bit k+1

	bit = 0x1 << k;
	x = x | bit;
	return	x;
}

int
nextBig(int x, int n)
{
	int	k, j;
	int	size= 8* sizeof(int);
	int	bit;
	int	mask;


	/* find the lowest bit 1 */
	for(k=0; k < size; k++)
		if ((x >> k & 0x1) == 0x1)
			break;

	/* find the lowest bit 0 which is higer than the lowest bit 1*/
	for(j=k; j < size; j++)
		if ((x >> j & 0x1) == 0)
			break;

	bit = 0x1 << k;
	mask = ~bit;
	x = x & mask;	// mask off bit k

	bit = 0x1 << j;	// flip the bit j
	x = x | bit;

	return	x;
}

int
NumberOfOnes(int x)
{
	int	k;
	int	count=0;
	int	size= 8* sizeof(int);

	for(k=0; k < size; k++)
		if (x >>k & 0x1)
			count++;

	return	count;
}
	
main()
{
	// int	x=0x123;
	int	x=0x1037;
	int	n1;
	int	smallest,biggest;

	n1 = NumberOfOnes(x);
	printf("x=0x%x, 1s=%d\n", x, n1);

	smallest = nextSmall(x, n1);
	printf("small=0x%x\n", smallest);

	biggest = nextBig(x, n1);
	printf("next big=0x%x\n", biggest);
}
