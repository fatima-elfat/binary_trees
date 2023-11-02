#include "binary_trees.h"
/**
 * binary_tree_rotate_left - performs a left-rotation
 * on a binary tree.
 * @tree: a pointer to the root node of the tree.
 * Return: a pointer to the new root node of
 * the tree once rotated.
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *bt_new, *tmp1, *tmp2;

	if (!tree || !tree->right)
		return (NULL);
	tmp1 = tree->parent;
	tmp2 = tree->right->left;
	bt_new = tree->right;
	bt_new->left = tree;
	tree->right = tmp2;
	tree->parent = bt_new;
	bt_new->parent = tmp1;
	return (bt_new);
}
