#include <stdio.h>
#include <stdlib.h>
#include "../include/linked_list.h"

LinkedList	*head = NULL;

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

/* Add the new node to the tail and return the tail */
LinkedList	*
LLAdd(int data)
{
	LinkedList	*p;
	LinkedList	*new;

	new = malloc(sizeof(LinkedList));
	new->data = data;
	new->next = NULL;

	if (head == NULL){
		head = new;
		return	new;
	}
	
	p = head;
	while (p->next != NULL)
		p = p->next;

	p->next = new;
	return	new;
}

main()
{
	LinkedList	*p;
	LinkedList	*q;
	extern	LinkedList	*runner();

	LLAdd(1);
	LLAdd(2);
	LLAdd(3);
	p= LLAdd(4);
	LLAdd(5);
	LLAdd(6);
	LLAdd(7);
	q = LLAdd(8);

	/* make the circular list */
	q->next = p;
	
	// LLPrint();

	p=runner(head);
	if (p == NULL)
		printf("No Circular head\n");
	else
		printf("Circular head: %d\n", p->data);

	// LLPrint();
}
