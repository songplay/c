/*
 *	Compress a string
 *	12/29/2016
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *
sc(char str[])
{
	int	i, j, k;
	int	len;
	int	count;
	char	*old;

	len = strlen(str);
	old = malloc(sizeof (len+1));
	strncpy(old, str, len);
	
	if (len < 1)
		return	str;

	for(i=0; i<len; i++, i++) {
		// printf("i=%d, len=%d\n", i, len);
		for(count=1, j=i+1; j<len+1; j++)
		if (str[i]==str[j])
			count++;
		else {
			if (count == 1){	// push back 
				for(k=len-1; k>=j; k--)
					str[k+1] = str[k];
				len++;
			}else {		// move forward
				for(k=i+2; k<len-count+2; k++)
					str[k] = str[k+count-2];

				len = len-count+2;
				str[len]='\0';	
			}

			str[i+1]= '0' + count;
			// printf("i=%d: j=%d, count=%d, len=%d, %s\n", i, j, count, len, str);
			break;
		}
	}

	if (strlen(str) > strlen(old))
		return	old;
	else
		return	str;
}


main()
{	
	char	data1[]="abbccc";
	char	data2[]="abbcccddddee";

	printf("%s\n", data1);
	printf("%s\n", sc(data1));
}
