/*
 *	sort it using qsort()
 */
#include <stdio.h>

int
mycompare(void *a, void *b)
{
	int	aa = * (int *)a;
	int	bb = * (int *)b;

	if (aa == bb)
		return	0;
	else if (aa > bb)
		return	1;
	else
		return	-1;
}

main()
{
	int	alice[10] = {1, 6, 444, 22, 45};
	int	k;

	/* Print the original array */
	for(k=0; k< 10; k++)
		printf("alice[%d] = %d\n", k, alice[k]);

	// sort(alice, 10);
	qsort(alice, 6, sizeof(int), mycompare);

	/* Print the result aftersorting */
	for(k=0; k< 10; k++)
		printf("alice[%d] = %d\n", k, alice[k]);
}
