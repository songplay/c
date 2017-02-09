/*
 * convert a 12 hour time into 24 hour
 */
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int
main() 
{
	char time[1024];
	char	*hour, *minute, *rest;
	char	second[8];
	char	pm[8];
	bool	is_pm = false;
	int	h;
	char	hh[8];
	int	len;

	scanf("%s", time);
	/* check the last two chars if they are pm */
	len = strlen(time);
	pm[0] = time[len-2];
	pm[1] = time[len-1];
	pm[0] = toupper(pm[0]);
	pm[1] = toupper(pm[1]);
	pm[2]='\0';
	
	if (strcmp(pm, "PM") == 0)
		is_pm = true;

	hour = strtok(time, ":");
	minute = strtok(NULL, ":");
	if (minute != NULL)
		*(minute+2) = '\0';
	rest = strtok(NULL, ":");

	/* check if the string second incluse the pm */
	if (rest ==NULL)
		second[0]='\0';
	else
		strncpy(second, rest, 2);

	if (is_pm){	/* need to convert the hours for the 24 hour format */
		sscanf(hour, "%d", &h);
		h = h + 12;
		if (h >= 24)
			h = h -12;
		sprintf(hh, "%d", h);
	} else 
		strcpy(hh, hour);

	printf("%s", hh);
	if (minute)
		printf(":%s", minute);
	if (second[0] != '\0')
		printf(":%s", second);

	printf("\n");
}
