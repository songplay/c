#include <stdio.h>
#include <stdint.h>

uint32_t
fab(uint32_t i)
{
	uint32_t	f, f1, f2;
	static	uint32_t	cache[100];

	if (i < 2)
		f = i;
	else {
		if (cache[i-2] > 0)
			f2 = cache[i-2];
		else
			f2 = fab(i-2);

		if (cache[i-1] > 0)
			f1 = cache[i-1];
		else
			f1 = fab(i-1);

		f = fab(i-1) + f2;
	}
	
	cache[i] = f;
	printf("fab[%d]=%d\n", i, f);
	return	f;
}

main()
{
	int	k=10;

	printf("fabonacci[%d]=%d\n", k, fab(k));
}
