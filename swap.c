#include <stdio.h>

main()
{
	int	a = 5;
	int	b = 9;

	a = a+b;
	b = a -b;
	a = a -b;

	printf("a=%d, b=%d\n", a, b);
}
