#include "binary_trees.h"
/**
 * bt_is_bst -  checks if a binary tree is a
 * valid Binary Search Tree.
 * @tree: a pointer to the root node of the tree to check.
 * @min: min.
 * @max: max.
 * Return: 1 on success.
*/
int bt_is_bst(const binary_tree_t *tree, int min, int max)
{
	int a, b;

	if (tree)
	{
		if (tree->n >= max || tree->n <= min)
			return (0);
		a = bt_is_bst(tree->left, min, tree->n);
		b = bt_is_bst(tree->right, tree->n, max);
		return((a && b));
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
