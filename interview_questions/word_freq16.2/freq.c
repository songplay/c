#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* convert a string to a lower case string */
char *
stolower(char *str)
{
	int	k,len;
	char	*p;

	p = str;
	len = strlen(str);
	for(k=0; k<len; k++, p++)
		*p = tolower(*p);
		
	return	str;
}

int
wcount(FILE *fp, char *word)
{
	char	buf[1024];
	int	count = 0;

	if (fp == NULL || word == NULL)
		return	0;

	while (!feof(fp)) {
		fscanf(fp, "%s", buf);
		strcpy(buf, stolower(buf));
		if (strcmp(buf, word)== 0)
			count++;
	}

	return	count;
}


main()
{
	char	*word="hello";
	char	*bookname ="book";
	FILE	*fp;
	
	fp =fopen(bookname, "r");
	if (fp!=NULL)
		printf("word=%s, count=%d\n", word, wcount(fp, word));

	return	0;
}
