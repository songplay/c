/*
 * utopian tree heigth.
 * the tree is 1 meter tall initially.
 * it will grow two cycles per year, double the height during summer, grow
 * 1 meter during summer.
 *
 * 1/31/2017
 */
#include <stdio.h>
#include <stdlib.h>

int
utopian(int cycle)
{

	if (cycle == 0)
		return	1;
	else if (cycle % 2 == 1)
		return 2*utopian(cycle-1);
	else if (cycle % 2 == 0)
		return	(utopian(cycle-1) + 1);
}

main()
{
	int	i;
	int	n;
	int	*cycles, *p;

	/* read the number of test cases */
	scanf("%d", &n);
	printf("n=%d\n",  n);

	cycles = malloc(n * sizeof(int));
	p = cycles;
	/* read cycles for each test */
	for(i=0; i<n; i++)
		scanf("%d", p++);

	/* print  out the results  */
	p = cycles;
	for(i=0; i<n; i++)
		printf("%d ",  utopian(*p++));

	printf("\n");
}
