#include <stdio.h>
#include <stdlib.h>
#include "bt.h"

static BT *head = NULL;

static int
BTDepth(BT *t)
{
	int	left, right;

	if (t == NULL)
		return	0;
	else {
		left = BTDepth(t->left) + 1;
		right = BTDepth(t->right) + 1;
		if (left > right)
			return	left;
		else
			return 	right;
	}
}

/* add a node to the tree */
Addit(BT *t, BT *new)
{
	int	left, right;

	if (t->left == NULL)
		t->left = new;
	else if (t->right == NULL)
		t->right = new;
	else {
		left = BTDepth(t->left);
		right = BTDepth(t->right);

		if (left > right)
			Addit(t->right, new);
		else
			Addit(t->left, new);
	}
}

/* add a node to the binary tree */
BTAdd(NODE *n)
{
	BT	*new;

	if (n == NULL)
		return;

	new = (BT *) malloc(sizeof(BT));
	new->node = n;
	new->left = new->right = NULL;

	if (head == NULL){
		head = new;
		return	0;
	}

	if (BTDepth(head->left) > BTDepth(head->right))
		Addit(head->right, new);
	else
		Addit(head->left, new);
}

/* remove nodes by id from binary tree */
int
BTRemove(BT *t, int id)
{
	int	count =0;

	if (t == NULL)
		return;

	if (t->left != NULL && t->left->node != NULL)
		if (t->left->node->id == id) {
			t->left = t->left->left;
			count++;
		}

	if (t->right != NULL && t->right->node != NULL)
		if (t->right->node->id == id) {
			t->right = t->right->right;
			count++;
		}

	count += BTRemove(t->right, id);
	count += BTRemove(t->left, id);
	return	count;
}

main()
{

}
