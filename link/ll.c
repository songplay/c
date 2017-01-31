#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

static LinkedList *head = NULL;

/* adda node to the list */
void
Add(NODE *n)
{
	LinkedList	*p = head;
	LinkedList	*new;

	new = (LinkedList *) malloc(sizeof (LinkedList));
	new->node = n;
	new->next = NULL;
	new->last = NULL;

	if (head == NULL){
		head = new;
		return;
	}

	while (p->next != NULL)
		p = p-> next;
		
	p->next = new;
	new->last = p;
}

/* remove a node by id from the list */
int
Remove(int id)
{
	LinkedList	*p = head;
	LinkedList	*new;

	if (head->node->id == id) {
		head = head->next;	/* add it as head */
		return	0;
	}

	while (p->next != NULL){
		if (p->next->node->id == id){
			if (p->next->next == NULL)	// delete the tail
				p->next = NULL;
			else {
				p->next->next->last = p;
				p->next =  p->next->next; 	
			}
			break;
		}
	}
}

main()
{
}
