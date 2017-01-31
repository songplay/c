/*
 *	Binary Serach test program
 */
#include <stdio.h>

main()
{
	int	a[]={2, 5, 23, 44, 456, 554};
	int	t=456;
	int	ret;
	extern int bsearch();

	ret = bsearch(a, 0, 5, t);
	printf("t=%d; ret=%d\n", t, ret);
}
