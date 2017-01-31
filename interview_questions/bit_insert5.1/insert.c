/*
 * Insert M into N from bit j to bit i.
 * 1/9/2017
 */
#include <stdio.h>
#include <stdint.h>

uint32_t
bit_insert(uint32_t n, uint32_t m, uint32_t j, uint32_t i)
{
	uint32_t	x, y, z;
	uint32_t	mask;
	int		k;

	mask =0x0;
	for(k=j; k<=i; k++)
		mask = mask<<1 | (0x1 << j);
	y = n & ~mask;

	x = m << j;
	z = y | x;
	return	z;
}
main()
{
	uint32_t	a;

	a = bit_insert(0x1000000, 0x101, 4, 6);
	printf("a=0x%x\n", a);
}
