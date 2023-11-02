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
	bt_new->parent = tree->right;
	bt_new->n = tree->n;
	bt_new->left = tree->left;
	bt_new->right = tree->right->left;
	tree->n = tree->right->n;
	tree->left = bt_new;
	tree->right = tree->right->right;
	return (tree);
}
