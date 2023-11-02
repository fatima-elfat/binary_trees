#include "binary_trees.h"
/**
 * bst_insert - inserts a value in a Binary Search Tree.
 * @tree: a double pointer to the root node
 * of the BST to insert the value.
 * @value: the value to store in the node to be inserted.
 * Return: a pointer to the created node, or NULL on failure.
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *bt_new, *tmp;

	if (tree)
	{
		tmp = *tree;
		if (!tmp)
		{
			bt_new = binary_tree_node(tmp, value);
			if (!bt_new)
				return (NULL);
			*tree = bt_new;
			return (*tree);
		}
		if (tmp->n > value)
		{
			if (tmp->left)
				return (bst_insert(&tmp->left, value));
			bt_new = binary_tree_node(tmp, value);
			if (!bt_new)
				return (NULL);
			tmp->left = bt_new;
			return (tmp->left);
		}
		if (tmp->n < value)
		{
			if (tmp->right)
				return (bst_insert(&tmp->right, value));
			bt_new = binary_tree_node(tmp, value);
			if (!bt_new)
				return (NULL);
			tmp->right = bt_new;
			return (tmp->right);
		}
	}
	return (NULL);
}
