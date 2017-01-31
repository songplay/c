/*
 *	Linked List header file
 */
typedef struct linked_list {
	int	data;
	struct linked_list *next;
} LinkedList;

extern LinkedList	*head;
