#include <stdio.h>
#include <stdint.h>

main()
{
	uint32_t	a, b;

	a = 0x100;
	b = 0x10;
	printf("a=0x%x, ~a=0x%x, a^b=0x%x\n", a, ~a, a^b);
	printf("b=0x%x, ~b=0x%x, a^b=0x%x\n", b, ~b, b^a);
}
