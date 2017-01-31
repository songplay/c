#include <stdio.h>


void
f2()
{
	int	*p = NULL;
	int	a;

	*p = 12;	// should panic
	a = *p;
}

f1()
{
	f2();
}

main()
{
	f1();
}
