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
	binary_tree_node_t *node = NULL, *sub_tree = NULL;

	if (!priority_queue)
		return (0);
	a = heap_extract(priority_queue);
	b = heap_extract(priority_queue);
	freq = (b) ? (a->freq + b->freq) : a->freq;
	c = symbol_create(-1, freq);
	sub_tree = binary_tree_node(NULL, c);
	if (!sub_tree)
		return (0);
	sub_tree->left = binary_tree_node(sub_tree, a);
	sub_tree->right = binary_tree_node(sub_tree, b);
	if (!sub_tree->left || !sub_tree->right)
		return (0);
	node = heap_insert(priority_queue, sub_tree);
	if (!node)
		return (0);
	return (1);
}
