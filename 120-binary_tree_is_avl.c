#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to
 * measure the height.
 * Return: height of the binary tree.
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h1 = 0, h2 = 0;

	if (tree)
	{
		if (tree->left)
			h1 = 1 + binary_tree_height(tree->left);
		if (tree->right)
			h2 = 1 + binary_tree_height(tree->right);
	}
	return ((h1 > h2) ? h1 : h2);
}
/**
 * bt_is_avl -  checks if a binary tree is avl.
 * @tree: a pointer to the root node of the tree to check.
 * @min: min.
 * @max: max.
 * Return: 1 on success.
*/
int bt_is_avl(const binary_tree_t *tree, int min, int max)
{
	int a, b, c;
	size_t h1, h2;

	if (tree)
	{
		h1 = binary_tree_height(tree->left);
		h2 = binary_tree_height(tree->right);
		if (tree->n >= max || tree->n <= min)
			return (0);
		c = h1 - h2;
		if (c > 1 || c < -1)
			return (0);
		a = bt_is_avl(tree->left, min, tree->n);
		b = bt_is_avl(tree->right, tree->n, max);
		return ((a && b));
	}
	return (1);
}
/**
 * binary_tree_is_avl -  checks if a binary tree is a
 * valid AVL Tree.
 * @tree: a pointer to the root node of the tree to check.
 * Return: 1 on success.
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int min, max;

	if (!tree)
		return (0);
	min = INT_MIN;
	max = INT_MAX;
	return (bt_is_avl(tree, min, max));
}
