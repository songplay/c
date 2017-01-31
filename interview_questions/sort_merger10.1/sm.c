/*
 * Merge two sorted arrays a and b into a
 */
void
merge(int a[], int alen, int b[], int blen)
{
	int	k;
	int	c[100];
	int	ap, bp, cp;
	int	r;

	ap = 0;
	bp = 0;
	cp = 0;
	while (bp < blen && ap < alen)
		if (a[ap] < b[bp])
			c[cp++] = a[ap++];
		else
			c[cp++] = b[bp++];

	/* copy the remaining */
	if (bp < blen) {
		r = blen - bp;
		for(k=0; k<r; k++)
			c[cp++] = b[bp++];
	}

	if (ap < alen) {
		r = alen - ap;
		for(k=0; k<r; k++)
			c[cp++] = a[ap++];
	}

	/* copy back from array c to a */
	for(k=0; k<cp; k++)
		a[k] = c[k];
}
