#include "binary_trees.h"
/**
 * array_to_bst - builds a Binary Search Tree from an array.
 * @array: a pointer to the first element of
 * the array to be converted.
 * @size: the number of element in the array.
 * Return: a pointer to the root node of the created BST, or NULL on failure.
*/
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i, j;
	bst_t *bt_new;

	if (!array)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
			if (array[i] == array[j])
				break;
		if (i == j)
			bst_insert(&bt_new, array[i]);
	}
	return (bt_new);
}
