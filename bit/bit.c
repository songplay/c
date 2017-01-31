/*
 * Caculate the absolute vaue of an integer
 * 1/2/2017
 */
#include <stdio.h>
#include <stdint.h>

uint32_t
myabs(int	x)
{
	uint32_t	n;
	int		y;
	int		z;

	y = x >> 31;	// shift the signed bit
	z = x+y;
	n = z ^ y;

	printf("x=0x%x, y=0x%x, z=0x%x\n", x, y, z);

	return	n;
}

main()
{
	int		x;
	uint32_t	n;

	n = myabs(x=0x80000002);
	printf("d=%d (%x), %d (%x)\n", x, x, n, n);

	n = myabs(x=0x10000002);
	printf("d=%d (%x), %d (%x)\n", x, x, n, n);
}
