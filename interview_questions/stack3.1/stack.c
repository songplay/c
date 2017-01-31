#include <stdio.h>

#define	ST	3	/* the number of stacks */
int	array[100];
int	sp[ST];		/* stack pointers	*/

void
push(int stack_no, int data)
{
	int	p = sp[stack_no];

	sp[stack_no] += ST;
	array[sp[stack_no]] = data;
}

int
pop(int stack_no)
{
	int	data;

	if (sp[stack_no] > stack_no)
		data = array[sp[stack_no]];

	sp[stack_no] -= ST;
	return	data;
}

int
peek(int stack_no)
{
	int	data;

	if (sp[stack_no] > stack_no)
		data = array[sp[stack_no]];

	return	data;
}

int
min(int stack_no)
{
	int	min;
	int	p;

	p = sp[stack_no];
	min = array[p];

	/* walk thru the stack */
	p -= ST;
	while (p > stack_no) {
		if (array[p] < min)
			min = array[p];

		p -= ST;
	}

	return	min;
}

void
init_sp()
{
	int	k;

	for(k=0; k<ST; k++)
		sp[k] = k;
}

main()
{
	init_sp();

}
