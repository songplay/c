/*
 * Multiply two numbers without using * operator
 * 1/12/17
 */
#include <stdio.h>

int
mul(int a, int b)
{
	int	x;

	printf("mul: a=%d, b=0x%x\n", a, b);

	if (a == 0 || b == 0)
		return	0;

	if (a == 1)
		return	b;

	if (b == 1)
		return	a;

	// x = mul(a, (b-1)) + a;
	if (b > 1)
		x = mul(a, (b>>1)) << 1;

	if (b & 0x1)
		x = x+a;

	printf("mul=%d 0x%x\n", x, x);
	return	x;
}

main()
{
	int	a, b;

	a=13;
	b=8;
	printf("a=%d, b=%d, x=%d\n", a, b, mul(a,b));
}
