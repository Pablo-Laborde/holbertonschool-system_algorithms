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
	binary_tree_node_t *node = NULL, *sub_node = NULL;

	heap = heap_create(compare_symbols);
	if (!heap)
		return (NULL);
	for (; i < size; i++)
	{
		sym = symbol_create(data[i], freq[i]);
		if (!sym)
			return (NULL);
		sub_node = binary_tree_node(NULL, sym);
		if (!sub_node)
			return (NULL);
		node = heap_insert(heap, sub_node);
		if (!node)
			return (NULL);
	}
	return (heap);
}


/**
 * compare_symbols- func
 * @a: void *
 * @b: void *
 * Return: int
 */
int compare_symbols(void *a, void *b)
{
	symbol_t *sym_a = NULL, *sym_b = NULL;

	sym_a = (symbol_t *)((binary_tree_node_t *)a)->data;
	sym_b = (symbol_t *)((binary_tree_node_t *)b)->data;
	return ((sym_a->freq > sym_b->freq) ? 1 : 0);
}


/**
 * binary_symbol_print- func
 * @node: binary_tree_node_t *
 * @lvl: int
 * Return: void
 */
void binary_symbol_print(binary_tree_node_t *node, int lvl)
{
	int i = 0;
	char c;
	symbol_t *sym = NULL;

	if (node)
	{
		sym = (symbol_t *)node->data;
		c = sym->data;
		if (c == -1)
			c = '$';
		for (; i < lvl; i++)
			printf("-");
		printf("%c/%ld", c, sym->freq);
		printf("\n");
		binary_symbol_print(node->left, lvl + 1);
		binary_symbol_print(node->right, lvl + 1);
	}
}
