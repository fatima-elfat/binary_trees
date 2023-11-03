#include "binary_trees.h"
/**
 * sa_to_avl - ...
 * @node: ...
 * @array: ...
 * @start: ...
 * @finish: ...
 * Return: ...
 */
avl_t *sa_to_avl(avl_t *node, int *array, int start, int finish)
{
	int a = 0;
	avl_t *root;
	binary_tree_t *aux;

	if (start <= finish)
	{
		a = (start + finish) / 2;
		a = ((start + finish) % 2 != 0) ? a : a - 1;
		aux = binary_tree_node((binary_tree_t *)node, array[a]);
		if (!aux)
			return (NULL);
		root = (avl_t *)aux;
		root->left = sa_to_avl(root, array, start, a - 1);
		root->right = sa_to_avl(root, array, a + 1, finish);
		return (root);
	}
	return (NULL);
}
/**
 * sorted_array_to_avl - builds a AVL from an array.
 * @array: a pointer to the first element of
 * the array to be converted.
 * @size: the number of element in the array.
 * Return: a pointer to the root node of the created avl,
 * or NULL on failure.
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	int f;

	if (!array || !size)
		return (NULL);
	f = (int)(size);
	return (sa_to_avl(NULL, array, 0, (f - 1)));          
}
