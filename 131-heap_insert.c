#include "binary_trees.h"
/**
 * binary_tree_size - measures the size of a binary tree.
 * @tree: a pointer to the root node of the tree to
 * measure the size.
 * Return: size of the binary tree.
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t s = 0;

	if (tree)
	{
		s = 1;
		if (tree->left)
			s += binary_tree_size(tree->left);
		if (tree->right)
			s += binary_tree_size(tree->right);
	}
	return (s);
}
/**
 * heap_insert - inserts a value in a Max Binary Heap.
 * @root: a double pointer to the root node
 * of the heap to insert the value.
 * @value: the value to store in the node to be inserted.
 * Return: a pointer to the created node, or NULL on failure.
*/
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_heap, *tree;
	int size, s1;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	new_heap = binary_tree_node(tree, value);
	return (new_heap);
}
