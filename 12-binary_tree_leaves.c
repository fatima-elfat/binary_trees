#include "binary_trees.h"
/**
 * binary_tree_leaves - measures the leaves of a binary tree.
 * @tree: a pointer to the root node of the tree to
 * measure the leaves.
 * Return: number of leaves in the binary tree.
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t l = 0;

	if (tree)
	{
		if (!tree->left && !tree->right)
			l += 1;
		if (tree->left)
			l += binary_tree_leaves(tree->left);
		if (tree->right)
			l += binary_tree_leaves(tree->right);
	}
	return (l);
}
