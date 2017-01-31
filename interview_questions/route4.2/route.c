/*
 * Find if there is a route from u to v in a directed graph
 * 1/8/2017
 */
#include	<stdio.h>
#include	<stdbool.h>

typedef struct vertice {
	int	airport;
	bool	visited;
	struct vertice	*next;	/* next in queue */
	struct vertice	*last;	/* next in queue */
	struct list {
		struct vertice *v;
		struct list	*next;/* the list of directed target vertices */
	} *head;
} VERTICE;

struct vertice *head =NULL;
struct vertice *tail =NULL;

void
enqueue(VERTICE *new)
{
	if (head == NULL){
		head = new;
		tail = new;
		new->next = NULL;
	} else {
		new->next = head;
		head = new;
	}
	head->last = NULL;
}


VERTICE *
dequeue(void)
{
	if (tail) {
		tail = tail->last;
		return tail->next;
	} else
		return	NULL;
}

/* deploy BFT search */
bool
route(VERTICE *u, VERTICE *v)
{
	struct list	*p;
	VERTICE		*n;

	if (u == v)
		return	true;

	/* check if v is among the u's direct target */
	u->visited = true;
	p = u->head;
	while (p != NULL) {
		if (p->v == u)
			return	true;
		else {
		/* if not, enqueue the u's unvisited direct target */
			if (!p->v->visited)
				enqueue(p->v);
			p= p->next;
		}
	}

	/* dequeue one vertice, and check if it reachs target v */
	n = dequeue();
	return	route(n, v);
}

main()
{

}
