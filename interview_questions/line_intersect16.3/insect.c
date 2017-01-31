/*
 *
 * Line 1: (a, b) and (c, d)
 * Line 2: (e, f) and (g, h)
 */
#include <stdio.h>

typedef struct node {
	int x;
	int y;
}  NODE;

typedef struct line  {
	NODE    n;
	NODE	m;
} LINE;

main()
{
	NODE	a = {2, 3};
	NODE	c = {2, 10};
	NODE	e = {3, 3};
	NODE	g = {5, 5};
	LINE	l1 = {a, c};
	LINE	l2 = {e, g};

/*
	l1.n.x * y + p = l1.n.y * x;
	l1.m.x * y + p = l1.m.y * x;

	l2.n.x * y + q = l2.n.y * x;
	l2.m.x * y + q = l2.m.y * x;
*/

	



}
