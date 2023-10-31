#include "binary_trees.h"
/**
 * binary_tree_depth - measures the depth of a binary tree.
 * @tree: a pointer to the root node of the tree to
 * measure the depth.
 * Return: depth of the binary tree.
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t d;

	if (tree)
	{
		if (!tree->parent)
			d = 0;
		else
			d = 1 + binary_tree_depth(tree->parent);
	}
	return (d);
}
