#include "binary_trees.h"
/**
 * bst_remove_rec - removes ...
 * @root: ...
 * @value: ...
 * Return: ...
*/
bst_t *bst_remove_rec(bst_t *root, bst_t *curr)
{
	bst_t *tmp1;

	tmp1 = curr->parent;
	if (!curr->right)
	{
		if (tmp1 && tmp1->left == curr)
			tmp1->left = curr->left;
		else if (tmp1)
			tmp1->right = curr->left;
		if (curr->left)
			curr->left->parent = tmp1;
		free(curr);
		if (tmp1)
			return (root);
		else
			(curr->left);
	}
	if (!curr->left)
	{
		if (tmp1 && tmp1->left == curr)
			tmp1->left = curr->right;
		else if (tmp1)
			tmp1->right = curr->right;
		if (curr->right)
			curr->right->parent = tmp1;
		free(curr);
		if (tmp1)
			return (root);
		else
			(curr->right);
	}
	while (curr->right->left != NULL)
		curr->right = curr->right->left;
	curr->n = curr->right->n;
	return (bst_delete(root, curr->n));
}
/**
 * bst_recmove - removes a curr from a Binary Search Tree.
 * @root: a pointer to the root curr of the tree
 * where you will remove a curr.
 * @curr: a pointer to the current curr of the tree.
 * @value: the value to remove in the tree.
 * Return: a pointer to the new root curr
 * of the tree after removing the desired value.
*/
bst_t *bst_recmove(bst_t *root, bst_t *curr, int value)
{
	if (curr)
	{
		if (curr->n < value)
			return (bst_recmove(root, curr->right, value));
		if (curr->n == value)
			return (bst_remove_rec(root, curr));
		if (curr->n > value)
			return (bst_recmove(root, curr->left, value));
	}
	return (NULL);
}
/**
 * bst_remove - removes a curr from a Binary Search Tree.
 * @root: a pointer to the root curr of the tree
 * where you will remove a curr.
 * @value: the value to remove in the tree.
 * Return: a pointer to the new root curr
 * of the tree after removing the desired value.
*/
bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return (NULL);
	return (bst_recmove(root, root, value)); 
}
