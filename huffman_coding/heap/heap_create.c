#include "heap.h"


/**
 * heap_create- func
 * @data_cmp: function pointer
 * Return: heap_t
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *root = NULL;

	root = malloc(sizeof(struct heap_s));
	if (!root)
		return(NULL);
	root->size = 0;
	root->data_cmp = data_cmp;
	root->root = NULL;
	return (root);
}
