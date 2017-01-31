#include <stdio.h>
#include <stdint.h>

typedef struct registerA {
	uint32_t	int_mask:4;
	uint32_t	offset:4;
	uint32_t	error:1;
} regA;

main()
{
	regA	x;
	uint8_t	*p;

	x.int_mask = 0x5;
	x.offset = 0x0;
	p = (uint8_t *) &x;

	printf("data = 0x%x\n", *p);
}
