/*
 *	sort an array using Bubble Sort
 */
#include <stdio.h>
#include <stdint.h>

void
bubble_sort(int	list[], uint32_t size)
{
	int	i, j, tmp;

	if (size == 0)
		return;

	for(i = 0; i < (size-1); i++)
	for(j = 0; j < (size - i - 1); j++)
		if (list[j] > list[j+1]){
/*
			tmp = list[j+1];
			list[j+1] = list[j];
			list[j] = tmp;
*/
			list[j] = list[j] + list[j+1];
			list[j+1] = list[j] - list[j+1];
			list[j] = list[j] - list[j+1];
		}
}


#define		SIZE	8	/* array size	*/
main()
{
	int	alice[SIZE] = {1, 6, 44, 2, 45};
	int	k;

	/* Print the original array */
	for(k=0; k< SIZE; k++)
		printf("alice[%d] = %d\n", k, alice[k]);

	bubble_sort(alice, 8);

	/* Print the result aftersorting */
	for(k=0; k< SIZE; k++)
		printf("alice[%d] = %d\n", k, alice[k]);
}
