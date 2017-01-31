/*
 *	Reverse a string
 */
#include	<stdio.h>
#include	<string.h>

#define	MAX	128
main()
{
	char	data0[]="Hello World 2233";
	char	data1[MAX];
	int	k;
	int	len;

	len = strlen(data0);
	if (len > MAX){
		fprintf(stderr, "The string is too big: %d\n", len);
		return (-1);
	}

	for(k = 0; k< len; k++)
		data1[len-k-1] = data0[k];

	data1[len] = '\0';
	printf("data1=%s\n", data1);
}
