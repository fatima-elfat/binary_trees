#include "binary_trees.h"
/**
 * binary_tree_depth - measures the depth of a binary tree.
 * @tree: a pointer to the root node of the tree to
 * measure the depth.
 * Return: depth of the binary tree.
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t d = 0;

	if (tree)
	{
		if (!tree->parent)
			d = 0;
		else
			d = 1 + binary_tree_depth(tree->parent);
	}
	return (d);
}

/**
 * binary_trees_ancestor - finds the lowest common
 * ancestor of two nodes.
 * @first: a pointer to the first node.
 * @second: a pointer to the second node.
 * Return: a pointer to the lowest common
 * ancestor node of the two given nodes.
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t d1, d2;

	if (first->parent == second->parent)
			return (first->parent);
	else
	{
		if (!first->parent && !second->parent)
			return (NULL);
		d1 = binary_tree_depth(first);
		d2 = binary_tree_depth(second);
		if (d2 < d1)
		{
			if (first->parent == second)
				return (second);
			binary_trees_ancestor(first->parent, second);
		}
		else
		{
			if (first == second->parent)
				return (second->parent);
			binary_trees_ancestor(first, second->parent);
		}
	}
}
