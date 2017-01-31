/*
 *	repcae the empty space by "%20" in a given string
 *	12/29/2016
 */
#include <stdio.h>
#include <stdlib.h>

char *
rs(char	str[], int len)
{
	int	j, k;

	for(k=0; k < len; k++)
		if (str[k] == ' '){
			for(j=len-1; j>k; j--)
				str[j+2] = str[j];

			str[len+2] = '\0';

			str[k] = '%';	
			str[k+1] = '2';	
			str[k+2] = '0';	
			len = len + 2;
		}
	return	str;
}

#pragma	GCC	push_options
#pragma GCC	optimize ("00")
main()
{
	char	data1[]="He llo world        ";
	char	data2[]=" Hello world        ";

	printf("%s\n", data1);
	printf("%s, %s\n", data1, rs(data1, 12));
	printf("%s, %s\n", data2, rs(data2, 12));
}
#pragma	GCC	pop_options
