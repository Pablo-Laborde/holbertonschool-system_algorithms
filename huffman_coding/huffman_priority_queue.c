#include "huffman.h"


/**
 * huffman_priority_queue- func
 * @data: char *
 * @freq: size_t *
 * @size: size_t
 * Return: heap_t *
 */
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	size_t i = 0;
	heap_t *heap = NULL;
	symbol_t *sym = NULL;
	binary_tree_node_t *node = NULL;

	heap = heap_create(NULL);
	if (!heap)
		return (NULL);
	for (; i < size; i++)
	{
		sym = symbol_create(data[i], freq[i]);
		if (!sym)
			return (NULL);
		node = heap_insert(heap, sym);
		if (!node)
			return (NULL);
		/* aux = (void *)node->data; must declare symbol_t *aux */
	}
	return (heap);
}
