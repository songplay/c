#include <stdio.h>
#include <stdarg.h>

int
my_total(int num, ...)
{
	va_list	l;
	int	total=0;
	int	k;

	va_start(l, num);
	for(k=0; k<num; k++)
		total = total + va_arg(l, int);
	va_end(l);

	return	total;
}


main()
{
	printf("T1=%d\n", my_total(3, 1, 10, 100));
	printf("T1=%d\n", my_total(5, 1, 10, 100, 1000, 1));

}
