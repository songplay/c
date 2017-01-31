/*
 * Check if a tree is balanced
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef	struct	tree {
	int	node;
	struct tree *left;
	struct tree *right;
} TREE;


/* return true if it Balaned tree, and depth is the tree depth */
bool
bt(TREE *root, int *depth)
{
	int	left_depth =0;	/* left subtree depth */
	int	right_depth=0;	/* right subtree depth */

	if (root == NULL) {
		*depth = 0;
		return	true;
	}

	if (!bt(root->left, &left_depth))
		return	false;

	if (!bt(root->right, &left_depth))
		return	false;

	if (abs(left_depth - right_depth) > 1)
		return	false;
	else {
		if (left_depth > right_depth)
			*depth = left_depth + 1;
		else
			*depth = right_depth + 1;
		return	true;
	}
}

main()
{

}

