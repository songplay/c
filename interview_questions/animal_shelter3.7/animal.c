/*
 * animal shelter queue
 * 1/5/2017
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
	dog = 2,
	cat = 3,
} animal_type;

typedef struct {
	char		name[80];
	animal_type	type;
} animal_t;

typedef struct linked_list {
	animal_t	*animal;
	struct linked_list	*next;		// next, any kind
	struct linked_list	*last;
} LinkedList;

LinkedList *head = NULL;
LinkedList *tail = NULL;

void
printq()
{
	LinkedList	*p;

	p = head;
	while (p!= NULL) {
		printf("%s,", p->animal->name);
		p = p->next;
	}

	printf("\nhead=%s\t", head->animal->name);
	printf("tail=%s\n", tail->animal->name);
}

void
enqueue0(animal_t *animal)
{
	LinkedList	*p;
	LinkedList	*new;

	new = malloc(sizeof (LinkedList));
	new->animal = animal;
	new->last = NULL;
	new->next= NULL;

	if (head == NULL) {
		head = new;
		tail = new;
	} else {
		new->next = head;
		head->last = new;
		head = new;
	}
}

void
enqueue(animal_type type, char  *name)
{
	animal_t	*p;

	p = malloc(sizeof(animal_t));
	p->type = type;
	strncpy(p->name, name, strlen(name)+1);

	enqueue0(p);
}

animal_t *
dequeue(animal_type type)
{
	LinkedList	*p;
	LinkedList	*q;

	if (tail == NULL)
		return	NULL;

	p = tail;
	if (p->animal->type == type) {	// pop the tail
		tail = tail->last;
		tail->next = NULL;
		if (p == head)
			head = NULL;

		return p->animal;
	}

	while (p->last != NULL) 
		if (p->last->animal->type == type) {
			q = p->last;
			if (p->last->last == NULL){ // pop the head
				head = q->next;
				head->last = NULL;
			} else {		// pop the middle
				q->last->next = p;
				p->last = q->last;
			}

			return	q->animal;
		} else
			p = p->last;

	return	NULL;
}

main()
{
	animal_t	*p;

	enqueue(dog, "a1");
	enqueue(dog, "b2");
	enqueue(cat, "c2");

	printq();

	p = dequeue(cat);
	printf("Poped: name=%s\n", p->name);
	printq();

}
