#include <stdio.h>

void
pr_stair(int n)
{
	int	i, k,j;

	for(k=0; k<=n; k++) {
		for(j=0; j<=n-k; j++)
			printf(" ");
		for(i=0; i<k; i++)
			printf("#");

		printf("\n");
	}

	printf("\n");
}

main()
{
	pr_stair(4);
}
