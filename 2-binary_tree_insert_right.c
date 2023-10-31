#include "binary_trees.h"
/**
 * binary_tree_insert_right - inserts a node as the
 * right-child of another node. If parent already has
 * a right-child, the new node must take its place,
 * and the old right-child must be set as the right-child of the new node..
 * @parent: a pointer to the parent node of the node to create.
 * @value: the value to put in the new node.
 * Return: a pointer to the created node, or NULL on
 * failure or if parent is NULL.
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *bt_new;

	if (!parent)
		return (NULL);
	bt_new = malloc(sizeof(binary_tree_t));
	if (!bt_new)
		return (NULL);
	bt_new->n = value;
	bt_new->parent = parent;
	bt_new->left = NULL;
	bt_new->right = NULL;
	if (parent->right)
	{
		bt_new->right = parent->right;
		parent->right->parent = bt_new;
	}
	parent->right = bt_new;
	return (bt_new);
}
