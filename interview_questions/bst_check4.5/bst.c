/*
 * check if a tree is binary serach tree
 * 1/8/2017
 */
#include <stdio.h>
#include <stdbool.h>

typedef	struct tree {
	int	data;
	struct tree *left;
	struct tree *right;
} TREE;

TREE *head=NULL;

bool
bst(TREE *t, int *depth)
{
	int	left, right;

	if (t == NULL){
		*depth = 0;
		return	true;
	}

	if (bst(t->left, &left) == false)
		return	false;

	if (bst(t->right, &right) == false)
		return	false;

	if (abs(left-right) > 1)
		return	false;
	else {
		if (left > right)
			*depth = left + 1;
		else
			*depth = right + 1;

		return	true;
	}
}

main()
{

}

