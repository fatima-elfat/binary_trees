#include "binary_trees.h"
/**
 * bst_recmove - removes a curr from a Binary Search Tree.
 * @root: a pointer to the root curr of the tree
 * where you will remove a curr.
 * @root: a pointer to the current curr of the tree.
 * @value: the value to remove in the tree.
 * Return: a pointer to the new root curr
 * of the tree after removing the desired value.
*/
bst_t *bst_recmove(bst_t *root, bst_t *curr, int value)
{
	bst_t *tmp;

	if (curr)
	{
		if (curr->n < value)
			return (bst_recmove(root, curr->right, value));
		if (curr->n == value)
		{
			if (!curr->left)
			{
				if (tmp && tmp->left == curr)
					tmp->left = curr->right;
				else if (tmp)
					tmp->right = curr->right;
				if (curr->right)
					curr->right->parent = tmp;
				free(curr);
				if (!tmp)
					return (curr->right);
				else
					return (root);
			}
		}
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
