#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list {
	int	data;
	struct linked_list	*next;
} LinkedList;

LinkedList	*head = NULL;

/* Delete the middle node in the list */
void
dm()
{
	LinkedList	*p;
	LinkedList	*q;
	LinkedList	*ql;
	LinkedList	*old;

	if (head == NULL)
		return;

	/* if only one node in the list */
	if (head->next == NULL) {
		free(head);
		head = NULL;
		return;
	}

	p = head->next;
	q = head;
	ql = head;
	while (p != NULL) {
		p = p->next;
		if (p != NULL) {
			p = p->next;
			ql = q;
			q = q->next;
		}
	}	

	old = ql->next;
	ql->next = ql->next->next;
	free(old);
}

void
LLPrint()
{
	LinkedList	*p;

	p = head;
	while (p != NULL){
		printf("%d, ", p->data);
		p = p->next;
	}
	printf("\n");
}

LLAdd(int data)
{
	LinkedList	*p;
	LinkedList	*new;

	new = malloc(sizeof(LinkedList));
	new->data = data;
	new->next = NULL;

	if (head == NULL){
		head = new;
		return;
	}
	
	p = head;
	while (p->next != NULL)
		p = p->next;

	p->next = new;
}

main()
{
	LLAdd(1);
	LLAdd(2);
	LLAdd(3);
/*
	LLAdd(4);
	LLAdd(5);
	LLAdd(6);
	LLAdd(7);
	LLAdd(8);
*/
	LLPrint();

	dm();
	LLPrint();
}
