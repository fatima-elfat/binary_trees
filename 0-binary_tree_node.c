#include "binary_trees.h"
/**
 * binary_tree_node - creates a binary tree node.
 * @parent: a pointer to the parent node of the node to create.
 * @value: the value to put in the new node.
 * Return: a pointer to the new node, or NULL on failure.
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *bt_new;

	bt_new = malloc(sizeof(binary_tree_t));
	if (!bt_new)
		return (NULL);
	bt_new->n = value;
	bt_new->parent = parent;
	bt_new->left = NULL;
	bt_new->right = NULL;
	return (bt_new);
}
