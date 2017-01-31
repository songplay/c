/*
 * Determine is binary tree T2 is a subtree of binary tree T1
 */
#include <stdio.h>
#include <stdbool.h>

typedef struct tree {
	int	id;
	struct tree *left;
	struct tree *right;
} TREE;

/* return true if the two tree are the same */
bool
tree_same(TREE *t, TREE *s)
{
	if (t==NULL && s==NULL)
		return	true;

	if (t->id == s->id && tree_same(t->left, s->left) &&
		 tree_same(t->right, s->right))
			return true;
		else
			return false;
}

bool
subtree(TREE *t, TREE *s)
{
	if (t == NULL && s== NULL)
		return	true;

	if (s == NULL)
		return	true;

	if (t == NULL && s!= NULL)
		return	false;

	if (t->id == s->id && tree_same(t->left, s->left) 
		&& tree_same(t->right, s->right))
		return	true;

	if (subtree(t->left, s) || subtree(t->right, s))
		return	true;
	else
		return	false;
}

main()
{

}
