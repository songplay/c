#include <stdio.h>
#include "../include/ll.h"
#include <stdbool.h>

bool
palindrome(LinkedList *h, int len)
{
	LinkedList	*p;
	int	k;

	if (len <= 1)
		return	true;

	if (len == 2)
		if (h->data == h->next->data)
			return	true;
		else
			return	false;

	p = h;
	k = len-1;
	while (p->next != NULL && k--) 
		p = p->next;

	if (h->data == p->data && palindrome(h->next, len -2))
		return	true;
	else
		return	false;

}

/* Caculate the length of the list */
int
LinkedListLen(LinkedList *h)
{
	LinkedList	*p;
	int	len = 0;

	p = h;
	while (p != NULL) {
		p = p->next;
		len++;
	}

	return	len;
}

bool
LnkedListPalindrome(LinkedList *h)
{
	int	len;

	len = LinkedListLen(h);
	return	palindrome(h, len);
}
