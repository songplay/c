#include <stdio.h>

typedef enum error_list {
	BAD_SYNTAX = 1,
	ILLEAGE_OPERAND = 2,
	BAD_GRAMMAR =  3
} errors;

main()
{
	printf("ILL=%d\n", ILLEAGE_OPERAND);

}
	
