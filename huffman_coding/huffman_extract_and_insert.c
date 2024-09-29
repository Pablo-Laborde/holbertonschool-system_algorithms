#include "huffman.h"


/**
 * huffman_extract_and_insert
 * @priority_queue: heap_t *
 * Return: int
 */
int huffman_extract_and_insert(heap_t *priority_queue)
{
	size_t freq = 0;
	symbol_t *a = NULL, *b = NULL, *c = NULL;
	binary_tree_node_t *node = NULL;

	if (!priority_queue)
		return (0);
	a = heap_extract(priority_queue);
	b = heap_extract(priority_queue);
	freq = (b) ? (a->freq + b->freq) : a->freq;
	c = symbol_create(-1, freq);
	node = heap_insert(priority_queue, c);
	if (!node)
		return (0);
	return (1);
}
