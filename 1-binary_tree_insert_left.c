#include "binary_trees.h"
/**
 * binary_tree_insert_left - inserts a node as the
 * left-child of another node. If parent already has a
 * left-child, the new node must take its place,
 * and the old left-child must be set as the
 * left-child of the new node.
 * @parent: a pointer to the parent node of the node to create.
 * @value: the value to put in the new node.
 * Return: a pointer to the created node, or NULL on
 * failure or if parent is NULL.
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
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
	if (parent->left)
	{
		bt_new->left = parent->left;
		parent->left->parent = bt_new;
	}
	parent->left = bt_new;
	return (bt_new);
}
