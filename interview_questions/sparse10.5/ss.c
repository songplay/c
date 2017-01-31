/*
 * Sparse search
 * 1/22/2017
 */
#include <stdio.h>
#include <string.h>

/* using binary search */
int
bsearch(char *d[], int l, int r, char *s)
{
	int	k, m;
	int	cmp;
	char	*ms;

	if (strcmp(d[l] ,s) == 0)
		return	l;

	if (strcmp(d[r] ,s) == 0)
		return	r;

	if (l == r && strcmp(d[l] ,s) != 0)
		return	-1;

	/* look for the string at middle */
	m = (l+r)/2;
	for(k=m; k<=r; k++)
		if (strcmp(d[k], "") != 0)
			break;
			
	// have to search it at left half while right half is empty
	if (k > r)	
		for(k=m; k>=l; k--)
			if (strcmp(d[k], "") != 0)
				break;
	m = k;
	cmp = strcmp(d[m], s);
	if (cmp == 0)
		return	m;
	else if (cmp < 0)	// s shold be at right half
		return	bsearch(d, m, r, s);
	else
		return	bsearch(d, l, m, s);
}


int
search(char *d[], int len, char *s)
{
	return	bsearch(d, 0, len -1, s);
}

main()
{	
	char	*msg[] = {"at", "", "", "", "ball", "ca", "", "car", "",
			 "dad", ""};
	char	str[]="dad";
	
	printf("%s: %d\n", str, search(msg, 11, str));
}
