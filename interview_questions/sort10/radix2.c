/*
 * Radix sort: all intergers
 * 1/17/2017
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct link {
	int	data;
	struct link *next;
} LINK;

LINK	*table[10];

/* Init the Hash table */
void
Init()
{
	int	k;

	for(k=0; k< 10; k++)
		table[k] = NULL;
}

/* Add to hash table */
void
Add(int item, int key)
{
	LINK	*new;
	LINK	*p;
	
	new = malloc(sizeof (LINK));
	new->data = item;
	new->next = NULL;

	if (key < 0)
		key = -key;

	if (table[key] == NULL)
		table[key] = new;
	else {
		p = table[key];
		while (p->next != NULL)
			p = p->next;

		p->next = new;
	}
}

/* copy from Hash Table back to array */
void
CopyBack(int a[])
{
	int	k;
	int	current=0;
	LINK	*p, *old;

	for(k=0; k< 10; k++) {
		p = table[k];
		while (p != NULL) {
			a[current++] = p->data;
			old = p;
			p = p->next;
			free(old);
		}
		table[k] = NULL;
	}
}


void
radix_sort(int a[], int len)
{
	int	i, j;
	int	left;
	int	base=1;
	bool	more=true;
	int	key;

	/* compare from 10's to 100s, 1000s, until none */
	do{
		Init();
		more = false;

		for(i=0; i < len; i++) {
			left = a[i] / base;
			key = left % 10;
			// printf("a[%d]=%d; left=%d, key=%d\n", i, a[i], left, key);
			if (left || more)
				more = true;

			// add the item to hash table
			Add(a[i], key);
		}

		CopyBack(a);
		// pr_array(a, len);
		base= base * 10;
	} while (more);		// more to compare
}

void
reverse(int a[], int len)
{
	int	b[1000];
	int	k;

	for(k=0; k< len; k++)
		b[k] = a[len -1 -k];

	for(k=0; k< len; k++)
		a[k] = b[k];
}

void
sort(int a[], int len)
{
	int	pa[100];	// array for non-negative numbers
	int	na[100];	// array for negative numbers
	int	k;
	int	p = 0;
	int	n = 0;

	if (len > 1) {
		/* split into negtaive array and non-negative array */
		for (k=0; k<len; k++)
			if (a[k] >= 0)
				pa[p++] = a[k];
			else
				na[n++] = a[k];

		radix_sort(pa, p);

		radix_sort(na, n);
		reverse(na, n);

		/* merge the two arrays back */
		for (k=0; k<n; k++)
			a[k] = na[k];
		for (k=0; k<p; k++)
			a[n+k] = pa[k];
	}
}
