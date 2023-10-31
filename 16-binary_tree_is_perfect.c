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
 * bt_is_perfect - checks if a binary tree is perfect.
 * @tree: a pointer to the root node of the tree to check.
 * @pd: the depth.
 * Return: 1 on success.
*/
int bt_is_perfect(const binary_tree_t *tree, int *pd)
{
	int d;

	if (tree)
	{
		if (!tree->left && !tree->right)
			{
				/** calculate and compare the dept of previous*/
				d = binary_tree_depth(tree);
				if (*pd == -1)
				{
					printf("here\n");
					*pd = d;
					printf("%d %d\n", *pd, d);
				}
				else
					return (0);
			}
		else if (!tree->left)
			return (0);
		else if (!tree->right)
			return (0);
		else
		{
			bt_is_perfect(tree->left, *pd);
			bt_is_perfect(tree->right, *pd);
		}
	}
	return (1);
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: a pointer to the root node of the tree to check.
 * Return: 1 on success.
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int *pd;

	pd = malloc(sizeof(int));
	if (!pd)
		return (NULL);
	*pd = -1;
	return(bt_is_perfect(tree, *pd));
}