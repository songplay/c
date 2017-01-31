/*
 *	Find the depth of a binary tree
 */
#include <stdio.h>
#include <stdint.h>

typedef	struct	btree {
	struct btree	*left;
	struct btree	*right;
} BINARY_TREE;


uint32_t
btd(BINARY_TREE *t)
{
	uint32_t	left, right;

	if (t == NULL)
		return	0;

	left = btd(t->left);
	right = btd(t->right);

	if (left > right)
		return	(left + 1);
	else
		return	(right + 1);
}

main()
{

}
