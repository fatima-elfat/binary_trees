#include "binary_trees.h"
/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: a pointer to the root node of the tree to check.
 * Return: 1 on success.
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (tree)
	{
		if (!tree->left && !tree->right)
			r = l = 1;
		if (tree->left)
			l = binary_tree_is_full(tree->left);
		if (tree->right)
			r = binary_tree_is_full(tree->right);
	}
	return (r * l);
}
