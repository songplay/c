/*
 	Probe the endiness of this system
 */
#include	<stdio.h>
#include	<stdint.h>

main()
{
	uint32_t	x=0x11223344;
	uint8_t		*p;

	p = (int8_t *) &x;
	printf("Byte= 0x%x\n", *p);

	if (*p == 0x11)
		printf("Big endian\n");
	else
		printf("Little endian\n");
}
