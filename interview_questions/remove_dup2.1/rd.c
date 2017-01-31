/*
 *	Remove the duplicates in linked list
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list {
	int	data;
	struct linked_list	*next;
}	LinkedList;

LinkedList	*head;

/* remove the node by data */
int
rd1(LinkedList *head, int data)
{
	LinkedList	*p, *q;
	int	count = 0;

	while (head != NULL)
		if (head->data == data) {
			q = head;
			head= head->next;
			count++;
			free(q);
		}else
			break;

	if (head == NULL)
		return count;

	p = head;
	while (p->next != NULL)
		if (p->next->data == data) {
			q = p->next;
			p->next = p->next->next;
			count++;
			free(q);
		}

	return	count;
}

/* remove the dup */
void
rd()
{
	LinkedList	*p;

	p = head;
	while (p != NULL) {
		rd1(p->next, p->data);
		p = p->next;
	}

	return;
}

main()
{

}
