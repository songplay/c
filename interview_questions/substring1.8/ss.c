/*
 *	find rotated sub string 
 *	12/30/2016
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void
rotate(char str[])
{
	int	len;
	int	k;
	int	tmp;

	len = strlen(str);
	tmp = str[0];
	for(k=0; k<len-1; k++)
		str[k] = str[k+1];

	str[len-1]=tmp;
}

/* if s2 is a s1's substring */
bool
IsSubString(char s1[], char s2[])
{
	int	len;
	int	k;
	char	*new;

	len = strlen(s2);
	new = malloc(len+1);
	strncpy(new, s2, len);
	*(new+len) = '\0';

	for(k=0; k<len; k++)
		if (strstr(s1, new))
			return	true;
		else
			rotate(new);
	
	return	false;
}


main()
{
	char	s1[]="Hello World";
	char	s2[]="Wor";
	char	s3[]="Wors";

	printf("%s, %s: %s\n", s1, s2, 
		IsSubString(s1, s2)? "Yes a substring" : "No");
	printf("%s, %s: %s\n", s1, s3, 
		IsSubString(s1, s3)? "Yes a substring" : "No");
}
