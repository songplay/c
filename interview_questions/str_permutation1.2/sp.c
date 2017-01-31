#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define	SIZE	100
uint8_t	Table1[SIZE];
uint8_t	Table2[SIZE];

void
InitTable(uint8_t table[])
{
	int	k;

	for(k=0; k<SIZE; k++)
		table[k] = 0;
}

uint8_t
HashKey(char c)
{
	uint8_t	index;

	index = c - 'a';
	index = index % SIZE;
	return	index;
}

void
Add(uint8_t table[], char c)
{
	int	index;
	
	index = HashKey(c);
	table[index]++;
}

void
FillTable(uint8_t table[], char str[])
{
	int	k, len;

	InitTable(table);
	len = strlen(str);
	for(k=0; k<len; k++)
		Add(table, str[k]);
}


bool
CompareTables(uint8_t t1[], uint8_t t2[])
{
	int	k;

	for(k=0; k<SIZE; k++)
		if (t1[k] != t2[k])
			return	false;

	return	true;
}

/* return true if the two strings are permutation */
bool
sp(char str1[], char str2[])
{
	int	len1, len2;

	len1 = strlen(str1);
	len2 = strlen(str2);
	if (len1 != len2)
		return	false;

	FillTable(Table1, str1);
	FillTable(Table2, str2);

	if (CompareTables(Table1, Table2))
		return	true;
	else
		return	false;
}

main()
{
	char	t1[]= "Hello";
	char	t2[]= "Hllle";

	printf("t1=%s, t2=%s\n", t1, t2);
	printf("String Permutation: %s\n", sp(t1, t2)?  "Yes" : "No");
}
