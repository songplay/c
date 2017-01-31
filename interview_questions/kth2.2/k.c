/*
 * To find the kth node from the end of the list
 *	1/1/2017
 */
#include <stdio.h>

typedef struct linked_list {
	int	data;
	struct linked_list	*next;
} LinkedList;

LinkedList *head;

/* Find the ith node from the head */
LinkedList *
kth2(LinkedList *h, int index)
{
	LinkedList	*p;
	int	count=0;

	if (h == NULL)
		return NULL;

	p = h;
	do {
		if (index == count)
			return p;
		
		p = p->next;
		count++;
	} while (p != NULL);

	return	NULL;
}


/* Caculate the length of the link */
int
ListLen(LinkedList *h)
{
	LinkedList *p;
	int	len=0;

	if (h == NULL)
		return	len;

	p = h;
	len = 1;
	while (p->next != NULL) {
		p=p->next;
		len++;
	}

	return	len;
}


/* Find the kth node from the list tail */
LinkedList *
kth(int k)
{
	int	len;

	len = ListLen(head);
	if (len == 0)
		return	NULL;
	else
		return	kth2(head, len-k);
}


main()
{

}
