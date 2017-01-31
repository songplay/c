/*
 *	Rotate an image 90 degree
 *	12/30/2016
 */
#include <stdio.h>
#include <stdint.h>

typedef uint32_t	PIXEL;
#define	SIZE	4	/* image dimesion */
typedef	PIXEL	Image[SIZE][SIZE];


void
printImg(Image p)
{
	int	j, k;
	
	for(j=0; j<SIZE; j++){
		for(k=0; k<SIZE; k++)
			printf("%d, ", p[j][k]);

		printf("\n");
	}
}

PixelSwap(PIXEL *p1, PIXEL *p2)
{
	PIXEL	tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


/* rotate the image 90 degree */
void
ir(Image p)
{
	uint32_t i, j;

	printImg(p);

	for(i=0; i< SIZE; i++)
	for(j=i; j<SIZE; j++) {
#ifdef	DEBUG
		printf("p[%d][%d]=%d, p[%d][%d]=%d\n",
			 i,j,p[i][j], j, i, p[j][i]);
#endif
		if (i != j)
			PixelSwap(&p[i][j], &p[j][i]);
#ifdef	DEBUG
		printf("p[%d][%d]=%d, p[%d][%d]=%d\n",
			 i,j,p[i][j], j, i, p[j][i]);
#endif
	}
}


main()
{
	Image	img1= {
			{1,2,3,4},
			 {11,12,13,14},
			 {21,22,23,24},
			{31,32,33,34}
			};
	
	ir(img1);
	printImg(img1);
}
