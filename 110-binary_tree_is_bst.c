#include "binary_trees.h"
/**
 * binary_tree_is_bst -  checks if a binary tree is a
 * valid Binary Search Tree.
 * @tree: a pointer to the root node of the tree to check.
 * @min: min.
 * @max: max.
 * Return: 1 on success.
*/
int bt_is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (0);
	if (tree)
	{
		if (tree->left &&
		(tree->n <= tree->left->n || tree->left->n <= min))
			return (0);
		if (tree->right &&
		(tree->n >= tree->right->n || tree->right->n >= max))
			return (0);
		bt_is_bst(tree->left, min, tree->n);
		bt_is_bst(tree->right, tree->n, max);
	}
	return (1);
}
/**
 * binary_tree_is_bst -  checks if a binary tree is a
 * valid Binary Search Tree.
 * @tree: a pointer to the root node of the tree to check.
 * Return: 1 on success.
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int min, max;

	if (!tree)
		return (0);
	min = INT_MIN;
	max = INT_MAX;
	return (bt_is_bst(tree, min, max));
}
