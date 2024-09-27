#include "heap.h"


/**
 * heap_create- func
 * @data_cmp: function pointer
 * Return: heap_t
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *heap = NULL;

	heap = malloc(sizeof(struct heap_s));
	if (!heap)
		return(NULL);
	heap->size = 0;
	heap->data_cmp = data_cmp;
	heap->root = NULL;
	return (heap);
}
