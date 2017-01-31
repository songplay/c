/*
 *	linked_list.h
 *
*/

typedef	struct node {
	int	id;
	void	*payload;
} NODE;

typedef struct linkedlist {
	struct linkedlist *last;
	struct linkedlist *next;
	NODE		*node;
} LinkedList;
