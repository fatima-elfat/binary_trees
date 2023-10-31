#include "binary_trees.h"
/**
 * binary_tree_nodes - measures the nodes of a binary tree.
 * @tree: a pointer to the root node of the tree to
 * measure the nodes.
 * Return: number of nodes in the binary tree.
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t n = 0;

	if (tree)
	{
		if (tree->left || tree->right)
			n = 1;
		if(tree->left)
			n += binary_tree_height(tree->left);
		if(tree->right)
			n += binary_tree_height(tree->right);
	}
	return (n);
}
