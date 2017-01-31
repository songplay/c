/*
 * Find a missing integer in a big file
 * (using bit map)
 * 1/24/2017
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define	SIZE1K	1024
#define	SIZE1M	(1024 * SIZE1K)
#define	SIZE1G	(1024 * SIZE1M)

void
setbitmap(uint a[], int len, int d)
{
	int	index;
	int	bit;
	
	index = d / 8;
	bit = (d % 8);

	if (index <= len)
		a[index] = a[index] | (0x1 << bit);
}

int
searchbitmap(uint a[], int len)
{
	int	j,k;
	uint	r;

	/* search the 1st bit with value 0 */
	for(k=0; k < len; k++)
		if (r = ~a[k]) {
			for (j=0; j < 8; j++)
				if (r>>j & 0x1)
					return (k*8+j);
		}

	return	0;
}

/* find the biggest in this file */
uint32_t
fileBiggest(FILE *fp)
{
	uint32_t	a[SIZE1M];
	int	d,len;
	int	size;
	uint32_t	biggest=0;

	while (!feof(fp)){
		fscanf(fp, "%d", &d);
		setbitmap(a, SIZE1M, d);
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
