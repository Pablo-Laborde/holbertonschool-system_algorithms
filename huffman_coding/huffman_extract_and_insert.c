#include "huffman.h"


/**
 * huffman_extract_and_insert - func
 * @priority_queue: heap_t *
 * Return: int
 */
int huffman_extract_and_insert(heap_t *priority_queue)
{
	size_t freq = 0;
	symbol_t *a = NULL, *b = NULL, *c = NULL;
	binary_tree_node_t	*l = NULL, *r = NULL,
						*node = NULL, *sub_tree = NULL;

	if (!priority_queue)
		return (0);
	l = heap_extract(priority_queue);
	r = heap_extract(priority_queue);
	a = (symbol_t *)(binary_tree_node_t *)l->data;
	b = (symbol_t *)(binary_tree_node_t *)r->data;
	freq = a->freq + b->freq;
	c = symbol_create(-1, freq);
	sub_tree = binary_tree_node(NULL, c);
	if (!sub_tree)
		return (0);
	sub_tree->left = l;
	sub_tree->right = r;
	l->parent = sub_tree;
	r->parent = sub_tree;
	node = heap_insert(priority_queue, sub_tree);
	if (!node)
		return (0);
	(void)node;
	return (1);
}
