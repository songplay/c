#include	<stdio.h>

typedef struct linkedlist {
	int	val;
	void	*p;
	struct	linkedlist	*next;
} LinkedList;

LinkedList  *head= NULL;


/* Sort a LinedList */
LinkedList *
Sort(LinkedList *head)
{
	LinkedList	*p;
	LinkedList	*last;
	LinkedList	*smallest;

	if (head == NULL)
		return	NULL;

	if (head->next == NULL)
		return	head;

	/* Walk thru the list and Find the smallest */
	smallest = head;
	last = head;
	p = head->next;
	do {
		if (p->val < smallest->val) 
			smallest = p;

		last = p;
		p = p->next;
	} while (p->next != NULL);

	last->next = smallest->next;	// removethe smallest from the list
	smallest->next = Sort(head->next);
	head = smallest;
}

/* Add to the list and keep the list in ascending order */
LinkedList *
Add(LinkedList *new)
{
	LinkedList	*p;
	LinkedList	*last;

	if (head == NULL){
		head = new;
		return	head;
	}

	p = head;
	do {
		/* check if reaching the end of the list */
		if (p->next == NULL){
			p->next = new;
			break;
		}

		if (p->val < new->val) {	// continue to the next
			last = p;
			p = p->next;
		} else {	// need to insert at here
			if (p == head)
				head = new;
			else
				last->next = new;

			new->next = p;
			break;
		}
	} while (p != NULL);
	
	return	head;
}

main()
{
	


}

