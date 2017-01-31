/*
 * Generate a binary search tree with an ordered array
 * 1/8/2017
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int	node;
	int	depth;
	struct tree	*left;
	struct tree	*right;
} TREE;

TREE	*head = NULL;

int
tree_depth(TREE *root)
{
	int	left, right;

	if (root == NULL)
		return	0;
	else{
		left= tree_depth(root->left);
		right= tree_depth(root->right);
		if (left > right)
			return	left+1;
		else
			return	right+1;
	}
}

/* Find the smallest in the tree, which should leftest leave */
TREE *
smallest(TREE *root)
{
	TREE	*p;

	if (root == NULL)
		return	NULL;

	if (root->left == NULL) 	// found it 
		return	root;
	else {
		p= smallest(root->left);

		if (p == root->left)
			root->left = NULL;

		root->depth = tree_depth(root);
		return	p;
	}
}

/* Add a new node to a tree and keep the balance, return the new root */
TREE *
Add0(TREE *root, TREE *new)
{
	TREE	*p;

	/* Always add to the right */
	if (root->right == NULL) {
		root->right = new;
		root->depth++;
	} else
		Add0(root->right, new);

	/* rebalance it */
	if (root->right->depth > root->left->depth+1 ) {
		/* right tree is too big */
		p = root;
		/* the smallest in right tree will be the new root */
		root = smallest(root->right);
		root->left = p;
		root->right = p->right;
		root->depth = root->right->depth - 1;

		return root;
	}
}

/* Add a new node to a tree */
void
Add(int	data)
{
	TREE	*new;

	/* allocate the tree node and init it */
	new = malloc(sizeof (TREE));
	new->node = data;
	new->depth = 1;

	if (head == NULL) {
		head = new;
		return;
	}

	/* always add to the right subtree */
	head = Add0(head, new) + 1;
}


#define		SIZE	100
main()
{
	int	k;
	int	myarray[SIZE];	/* in order of increasing */

	for(k=0; k < SIZE; k++)
		Add(myarray[k]);
}
