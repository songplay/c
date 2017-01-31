/*
 * Determine if a string consists of unique chars
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool
uc(char	str[])
{
	int	j, k, len;

	len = strlen(str);
	for(k=0; k<len; k++)
	for(j=k+1; j<len; j++)
		if (str[k] == str[j])
			return	false;

	return	true;
}

main()
{
	char	data[] = "song";
	char	data1[] = "sing a song";

	printf("%s: Unique Char= %s\n", data, uc(data)? "Yes": "No");
	printf("%s: Unique Char= %s\n", data1, uc(data1)? "Yes": "No");
}
