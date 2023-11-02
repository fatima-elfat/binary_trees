#include "binary_trees.h"
/**
 * binary_tree_is_bst -  checks if a binary tree is a
 * valid Binary Search Tree.
 * @tree: a pointer to the root node of the tree to check.
 * Return: 1 on success.
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (tree)
	{
		if (tree->left && tree->n <= tree->left->n)
			return (0);
		if (tree->right &&tree->n >= tree->right->n)
			return (0);
		binary_tree_is_bst(tree->left);
		binary_tree_is_bst(tree->left);
	}
	return (1);
}
