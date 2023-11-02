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
	binary_tree_t *bt_new;

	if (!tree || !tree->right)
		return (NULL);
	bt_new = tree;
	bt_new->parent = tree->right;
	bt_new->right = tree->right->left;
	tree->left = bt_new;
	if (tree->right)
	{
		tree->n = 0;
		tree->right = NULL;
	}
	tree->n = tree->right->n;
	tree->right = tree->right->right;
	return (tree);
}
