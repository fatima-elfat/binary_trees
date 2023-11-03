#include "binary_trees.h"
/**
 * array_to_avl - builds a AVVL from an array.
 * @array: a pointer to the first element of
 * the array to be converted.
 * @size: the number of element in the array.
 * Return: a pointer to the root node of the created avl,
 * or NULL on failure.
*/
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i, j;
	bst_t *avl_new = NULL;

	if (!array)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		/**checks if val already exists*/
		for (j = 0; j < i; j++)
			if (array[i] == array[j])
				break;
		avl_insert(&avl_new, array[i]);
	}
	return (avl_new);
}
