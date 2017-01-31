/*
 * Swap the even bits with odd bits in a number
 * 1/9/2017
 */
#include <stdio.h>
#include <stdint.h>

uint32_t
swap(uint32_t a)
{
	return  ((a>>1) & (0x55555555)) | ((a<<1) & 0xaaaaaaaa);
}


main()
{
	uint32_t	x;

	x =0x13;
	printf("x=0x%x, swap=0x%x\n", x, swap(x));

	x =0x157;
	printf("x=0x%x, swap=0x%x\n", x, swap(x));
}

