#include <stdio.h>
#include <stdint.h>

uint32_t
fab(uint32_t i)
{
	uint32_t	f;
	static	uint32_t	cache[100];

	if (i < 2)
		f = i;
	else if (cache[i] > 0)
		f = cache[i];
	else 
		f = fab(i-1) + fab(i-2);

	cache[i] = f;
	printf("fab[%d]=%d\n", i, f);
	return	f;
}

main()
{
	int	k=12;

	printf("fabonacci[%d]=%d\n", k, fab(k));
}
