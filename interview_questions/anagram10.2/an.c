/*
 * Sort anagrams: use hash table
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define	PRIME	37
#define	SIZE	1024

/* sort a string so that the char are  in order of ascii value */
char *
ssort(char a[])
{

}

/* caculate the hash key for a string */
uint32_t
hkey(char a[])
{
	int	k, len;
	uint32_t	key=0;

	len = strlen(a);
	for(k=0; k < len; k++)
		key = key * PRIME + (int) (a[k] - 'a');

	return	(key % SIZE);
}

/* assume the string only contains lower casechar */
bool
isanagram(char a[], char b[])
{
	int	k;
	int	alen, blen;
	char	*p;
	char	*q;
	char	c[100];

	if (a == NULL || b == NULL)
		return	false;

	alen = strlen(a);
	blen = strlen(b);

	if (alen != blen)
		return	false;

	/* copy array b to c */
	for(k=0; k < blen; k++)
		c[k] = b[k];

	q = c;
	for(k=0; k < alen; k++){
		p = memchr(q, a[k], alen);
		if (p == NULL)
			return	false;

		/* delete the found char in array c */
		if (p == q)	// found it at 1st
			q = p+1;	// new head
		else {
			p++;
			*(p-1) = '\0';	// make two strings
			strcat(q, p);	// cat together
		}
	}

	return	true;
}


void
sort(char *a[], int len)
{
	int	j, k;
	int	current;
	char	*b[100];

	current = 0;
	for(k=0; k< len; k++)
		if (a[k] != NULL) {
			b[current++] = a[k];
			for(j=k+1; j < len; j++)
				if (isanagram(a[k], a[j])) {
					b[current++] = a[j];
					a[j] = NULL;
				}
		}

	/* copy it back */
	for(k=0; k< len; k++)
		a[k] = b[k];
}

void
pr_array(char *a[], int len)
{
	int	k;

	for(k=0; k<len; k++)
		printf("%s, ", a[k]);

	printf("\n");
}

main()
{
	char	*a[] = {"orWld", "Hello", "World", "eHllo", "olleH"};
	char	msg[] = "Hello";
	char	msg2[] = "Hlelo";
/*
	pr_array(a, 5);
	sort(a, 5);
	pr_array(a, 5);
*/

	printf("%s: hkey=%d\n", msg, hkey(msg));
	printf("%s: hkey=%d\n", msg2, hkey(msg2));

	// printf("result= %s\n", isanagram("hallo", "lehlo")? "true":"false");
}
