#include <stdio.h>

typedef	struct linked_list {
	int	data;
	struct linked_list	*next;
} LinkedList;

LinkedList	*head;

LinkedList *
Add(LinkedList *h, LinkedList *new)
{
	if (h == NULL)
		h = new;
	else
		new->next = h;

	return	new;
}


LinkedList *
px(LinkedList *h, int	x)
{
	LinkedList	*h1 = NULL;
	LinkedList	*h2 = NULL;
	LinkedList	*p, *p1, *p2;

	if (h == NULL)
		return NULL;

	p = h;
	while (p != NULL)
		if (p->data > x)
			p1 = Add(h2, p);
		else
			p2 = Add(h1, p);

	if (h1 != NULL) {
		h = h1;
		p1->next = h2;
	} else
		h = h2;

	return	h;
}


main()
{

}
