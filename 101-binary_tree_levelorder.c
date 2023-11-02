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
		if (tree->left)
			h1 = 1 + binary_tree_height(tree->left);
		if (tree->right)
			h2 = 1 + binary_tree_height(tree->right);
	}
	return ((h1 > h2) ? h1 : h2);
}
/**
 * bt_levelorder - goes through a binary tree
 * using pre-order traversal.
 * @tree: a pointer to the root node of the tree to traverse.
 * @func: a pointer to a function to call for each node.
 * @level: the current level.
 * The value in the node must be passed as a parameter
 * to this function.
*/
void bt_levelorder(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (!tree)
        return;
    if (!level)
        func(tree->n);
    else if (level > 0)
	{
		level--;
        bt_levelorder(tree->left, func, level);
        bt_levelorder(tree->right, func, level);
    }
}
/**
 * binary_tree_levelorder - goes through a binary tree
 * using pre-order traversal.
 * @tree: a pointer to the root node of the tree to traverse.
 * @func: a pointer to a function to call for each node.
 * The value in the node must be passed as a parameter
 * to this function.
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, i;

	if (!tree && !func)
		return;
	/** get height if 0 then do func*/
	h = binary_tree_height(tree);
	for (i = 0; i < h; i++)
		bt_levelorder(tree, func, i);
}

