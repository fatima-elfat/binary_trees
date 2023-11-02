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
 * bt_levelorder - goes through a binary tree
 * using pre-order traversal.
 * @tree: a pointer to the root node of the tree to traverse.
 * @level: the current level.
 * @a: ...
 * Return: 0 or 1.
*/
int  bt_levelorder(const binary_tree_t *tree, size_t level, size_t *a)
{
	if (!tree)
		return;
	else
	{
		level--;
		if (tree->left)
		{
			if (*a == 1)
				return (0);
			bt_levelorder(tree->left, level, a);
		}
		else
			*a = 1;
		if (tree->right)
		{
			if (*a == 1)
				return (0);
			bt_levelorder(tree->right, level, a);
		}
		else
			*a = 1;
	}
	return (1);
}
/**
 * binary_tree_is_complete - checks if a binary tree is complete.
 * @tree: a pointer to the root node of the tree to check.
 * Return: 1 on success.
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t a = 0, b, h, i;

	if (!tree)
		return (0);
	h = binary_tree_height(tree);
	for (i = 0; i < h + 1; i++)
		b = bt_levelorder(tree, i, &a);
	return (b);
}
