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
		if(tree->left)
			h1 = 1 + binary_tree_height(tree->left);
		if(tree->right)
			h2 = 1 + binary_tree_height(tree->right);
	}
	return ((h1 > h2) ? h1 : h2);
}
/**
 * binary_tree_balance - measures the balance of a binary tree.
 * @tree: a pointer to the root node of the tree to
 * measure the balance factor
 * Return: the balance of the binary tree.
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int h1 = 0, h2 = 0;

	if (tree)
	{
		if(tree->left)
			h1 = 1 + binary_tree_height(tree->left);
		if(tree->right)
			h2 = 1 + binary_tree_height(tree->right);
	}
	return (h1 - h2);	
}
