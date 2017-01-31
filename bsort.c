/*
 *	sort an array using Bubble Sort
 */
#include <stdio.h>
#include <stdint.h>

void
bsort(int list[], uint32_t size)
{
	int	k, j, tmp;

	if (size == 0)
		return;

	for (k = 0; k < size -1; k++) 
	for (j = 0; j < size - k -1; j++)
		if (list[j] > list[j + 1]){
			tmp = list[j+1];
			list[j+1] = list[j];
			list[j] = tmp;
		}
}

#define		SIZE	8	/* array size	*/
main()
{
	int	alice[SIZE] = {1, 6, 44, 22, 45};
	int	k;

	/* Print the original array */
	for(k=0; k< SIZE; k++)
		printf("alice[%d] = %d\n", k, alice[k]);

	bsort(alice, 8);

	/* Print the result aftersorting */
	for(k=0; k< SIZE; k++)
		printf("alice[%d] = %d\n", k, alice[k]);
}
