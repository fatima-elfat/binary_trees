#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs a right-rotation
 * on a binary tree.
 * @tree: a pointer to the root node of the tree.
 * Return: a pointer to the new root node of
 * the tree once rotated.
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *bt_new, *tmp1, *tmp2;

	if (!tree || !tree->left)
		return (NULL);
	tmp1 = tree->parent;
	tmp2 = tree->left->right;
	bt_new = tree->left;
	bt_new->right = tree;
	tree->left = tmp2;
	tree->parent = bt_new;
	if (tmp1)
	{
		if (tmp1->right == tree)
			tmp1->right = bt_new;
		else
			tmp1->left = bt_new;
	}
	bt_new->parent = tmp1;
	return (bt_new);
}
