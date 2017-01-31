#include <stdio.h>

main()
{
	int	a;
	int	b;

	a = 12;
	b = 33;
	printf("a=%d, b=%d\n", a, b);

	/* swap a and b */
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a=%d, b=%d\n", a, b);
	return	0;
}

