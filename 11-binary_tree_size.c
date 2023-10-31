#include "binary_trees.h"
/**
 * binary_tree_size - measures the size of a binary tree.
 * @tree: a pointer to the root node of the tree to
 * measure the size.
 * Return: size of the binary tree.
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t s = 0;

	if (tree)
	{
		s = 1;
		if (tree->left)
			s += binary_tree_size(tree->left);
		if (tree->right)
			s += binary_tree_size(tree->right);
	}
	return (s);
}
