#include <stdio.h>
#include <stdint.h>

main()
{
	double	a = 0.1;
	uint64_t	*y;

	y = (uint64_t *) &a;

	a = 0;
	printf("a=%f, y=0x%llx\n", a, (uint64_t) *y);

	a = 1;
	printf("a=%f, y=0x%llx\n", a, (uint64_t) *y);

	a = -1;
	printf("a=%f, y=0x%llx\n", a, (uint64_t) *y);

	a = 0.1;
	printf("a=%f, y=0x%llx\n", a, (uint64_t) *y);

	a = -0.1;
	printf("a=%f, y=0x%llx\n", a, (uint64_t) *y);
}
