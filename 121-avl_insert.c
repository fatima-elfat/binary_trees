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
 * getheightdif - ...
 * @tree: ...
 * Return: the height difference.
 */
int getheightdif(const binary_tree_t *tree)
{
	size_t h1, h2;

	if (!tree)
		return (0);
	h1 = binary_tree_height(tree->left);
	h2 = binary_tree_height(tree->right);
	return (h1 - h2);
}
/**
 * avl_insert_rec - ...
 * @tree: ...
 * @value: ...
 * @parent: ...
 * @avl_new: ...
 * Return: ...
 */
avl_t *avl_insert_rec(avl_t **tree, int value, avl_t *parent,
		avl_t **avl_new)
{
	int a;

	if (!*tree)
		return (*avl_new = binary_tree_node(parent, value));
	if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right,
		*tree, avl_new, value);
		if ((*tree)->right)
			return (NULL);
	}
	else if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left,
		*tree, avl_new, value);
		if (!(*tree)->left)
			return (NULL);
	}
	else
		return (*tree);
	/** check if avl if not rotate */
	a = getheightdif(*tree);
	if (a < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (a < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (a > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (a > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	return (*tree);
}
/**
 * avl_insert - inserts a value in a AVL.
 * @tree: a double pointer to the root node
 * of the avl to insert the value.
 * @value: the value to store in the node to be inserted.
 * Return: a pointer to the created node, or NULL on failure.
*/
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *avl_avl_new;

	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_avl_new = NULL;
	avl_insert_rec(tree, value, *tree, &avl_avl_new);
	return (avl_avl_new);
}
