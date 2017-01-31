/*
 * Modify a constant variable
 */
#include	<stdio.h>

main()
{
	const	int	a = 100;
	int	*p;


	printf("a= %d\n", a);

	p = (int *) &a;
	*p = 200;
	printf("New a= %d\n", a);

}
