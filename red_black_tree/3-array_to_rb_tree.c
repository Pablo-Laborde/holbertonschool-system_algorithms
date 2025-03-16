#include "rb_trees.h"


/**
 * array_to_rb_tree - func
 * @array: array of values
 * @size: size of array
 * Return: pointer to the root node
 */
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	size_t i = 0;
	rb_tree_t *root = NULL;

	for (; i < size; i++)
		rb_tree_insert(&root, array[i]);
	return (root);
}
