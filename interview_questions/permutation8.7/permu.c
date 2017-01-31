#include <stdio.h>



permu(char str[], int len)
{
	int	i;
	char	*str1;

	str1 = malloc(len);
	for (i=0; i < len; i++) {
		strncpy(str1, str, i); 
		strncat(str1, str[i+1], len - i -1); 

		save_perm(str[i] + permu(str1, len -1));
	}

	free(str1);
}



main()
{

}
