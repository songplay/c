#include <stdio.h>
#include "../include/linked_list.h"


/* Find the head of broken circular list */
LinkedList	*
FindHead(LinkedList *h, LinkedList *h2)
{
	LinkedList	*p;
	LinkedList	*p2;
	LinkedList	*save;

	/* break the loop */
	save = h2->next;
	h2->next = NULL;

	/* walk thru list 2 */
	p2 = save;
	while (p2 != NULL) {
		p2 = p2->next;
		p = h;
		while (p != NULL){
			if (p == p2){
				h2->next = save;
				return p;
			}
			p = p->next;
		}
	}
	return	NULL;
}

LinkedList	*
runner(LinkedList *h)
{
	LinkedList	*fast;
	LinkedList	*slow;

	fast = slow = h;

	while (fast != NULL) {
		fast = fast->next;
		if (fast == slow) // now it is in loop
			return FindHead(h, fast);			

		if (fast != NULL)
			fast = fast->next;
		
		if (fast == slow) 	// now it is in loop
			return FindHead(h, fast);			

		slow = slow->next;
	}

	return	NULL;
}
