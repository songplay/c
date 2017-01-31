/*
 * caculate the number of ways to climb a stairs
 * assuming you may climb in 1 step, or two steps, or three steps
 */
#include <stdio.h>

int
ways(int  steps)
{
	int	counts;
	int	count1 = 0;
	int	count2 = 0;
	int	count3 = 0;
	static int	data[1000];

	if (steps == 0)
		counts = 1;
	else if (steps == 1)
		counts = 1;
	else if (steps == 2) {
		count1= ways(steps-1);
		count2= 1;
		counts = count1 + count2;
	} else {
		/* 1 step for next step */
		if (data[steps-1])
			count1 = data[steps-1];
		else
			count1= ways(steps-1);

		if (data[steps-2])
			count2 = data[steps-2];
		else
			count2= ways(steps-2);

		if (data[steps-3])
			count3 = data[steps-3];
		else
			count3= ways(steps-3);

		counts = count1 + count2 + count3;
	}

	data[steps] = counts;
	return	counts;
}


main()
{
	int	s=2;

	for(s=1; s < 7; s++)
		printf("ways[%d]=%d\n", s, ways(s));

}
