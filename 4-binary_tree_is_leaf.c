#include "binary_trees.h"
/**
 * binary_tree_is_leaf - checks if a node is a leaf.
 * @node: a pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0.
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	int r = 0;

	if (node && !node->left && !node->right)
		r = 1;
	return (r);
}
