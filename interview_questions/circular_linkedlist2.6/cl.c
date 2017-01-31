/*
 * Find the head of circular list
 * 1/2/2017
 */
#include <stdio.h>
#include "../include/linked_list.h"

#define	MARK	0x80000000

/* return the head of circular list or NULL */
LinkedList *
cl(LinkedList *head)
{
	LinkedList	*p;

	p = head;
	while (p != NULL) {
		if (p->data & MARK) {
			p->data = p->data & ~(MARK);
			return	p;
		}

		p->data = p->data | MARK;
		p=p->next;
	}

	return	NULL;
}
