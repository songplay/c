/*
 * Find the next node of a given node in a binary search tree
 *	1/8/2017
 */
#include <stdio.h>

typedef struct tree {
	int	data;
	struct tree *left;
	struct tree *right;
} TREE;

TREE *root=NULL;

TREE *
bst_next(TREE *root, int new)
{
	TREE	*p;

	if (root == NULL)
		return	NULL;

	if (new == root->data)
		return	root;

	if (new < root->data) {	// go to left subtree to find
		p = bst_next(root->left, new);
		if (p)		// found it
			return	p;
		else
			return	root;
	}

	if (new > root->data) {
		p = bst_next(root->right, new);
		return	p;
	}
}

main()
{


}

	
