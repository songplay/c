/*
 *	one list link represents a number in the way that each node stores
 *	one digit.`
 *	Add two numbers.
 *	1/2/2017
 */
#include <stdio.h>
#include <stdlib.h>
#include "../include/ll.h"

/* return the tail */
LinkedList *
Add(LinkedList *last, LinkedList *h1, LinkedList *h2)
{
	LinkedList	*new;

	new = (LinkedList *) malloc(sizeof(LinkedList));
	new->data = h1->data + h2->data;
	new->next = NULL;

	last->next = new;
	return	new;
}

LinkedList *
LLAdd(LinkedList *h1, LinkedList *h2)
{
	LinkedList	*p1, *p2;
	LinkedList	*head = NULL;
	LinkedList	*last = NULL;

	p1 = h1;
	p2 = h2;

	while (p1 != NULL && p2 !=NULL) {
		last = Add(last, p1, p2);
		if (head == NULL)
			head = last;

		p1 = p1->next;
		p2 = p2->next;
	}

	if (p1 == NULL)
		last->next = p2;
	else if (p2 == NULL)
		last->next = p1;
	
	return	head;
}


main()
{

}

