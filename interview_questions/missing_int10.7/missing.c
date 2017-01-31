/*
 * Find a missing integer in a big file
 * 1/24/2017
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define	SIZE1K	1024
#define	SIZE1M	(1024 * SIZE1K)
#define	SIZE1G	(1024 * SIZE1M)

int
partition(uint32_t a[], int begin, int end)
{
	int	pivot;
	int	tmp;
	
	pivot = a[(begin + end)/2];

	while (begin <= end) {
		if (a[begin] < pivot)
			begin++;
		if (pivot < a[end])
			end--;

		//swap
		tmp = a[begin];
		a[begin] =a[end];
		a[end] =tmp;
		begin++;
		end--;
	}

	return begin;
}

void
quicksort(uint32_t a[], int begin, int end)
{
	int	m;

	if (begin <end) {
		m = partition(a, begin, end);
		quicksort(a, begin, m-1);
		quicksort(a, m, end);
	}
}

/* find the biggest in this file */
uint32_t
fileBiggest(FILE *fp)
{
	uint32_t	a[SIZE1M];
	int	k,len;
	int	size;
	uint32_t	biggest=0;

	size =  sizeof(uint32_t);

	/* read block by block due to memory limit */
	while (!feof(fp)){
		len= fread(a, size, SIZE1M, fp);
		quicksort(a, 0, len-1);
		/* after sorting array, the largest is at the end */
		if (biggest < a[len-1])
			biggest = a[len-1];
	}
	return	biggest;
}

uint32_t
fileMissing(FILE *fp)
{
	return	(fileBiggest(fp) + 1);
}

main()
{
	char	filename[]="test.dat";
	FILE	*fp;

	/* open the file */
	fp = fopen(filename, "r");
	if (fp ==NULL) {
		fprintf(stderr, "Can't open file %s\n", filename);
		exit	(-1);
	} else {
		printf("Missing Int= %d\n", fileMissing(fp));
		exit (0);
	}
}
