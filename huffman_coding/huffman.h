#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <stdlib.h>
#include "heap/heap.h"

/**
 * struct symbol_s - Stores a char and its associated frequency
 *
 * @data: The character
 * @freq: The associated frequency
 */
typedef struct symbol_s
{
	char data;
	size_t freq;
} symbol_t;


/* Functions */

	/* symbol.c */
		symbol_t *symbol_create(char data, size_t freq);

	/* huffman_priority_queue.c */
		heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size);
		int compare_symbols(void *a, void *b);
		int huffman_extract_and_insert(heap_t *priority_queue);
		void binary_symbol_print(binary_tree_node_t *node, int lvl);

	/* huffman_tree.c */
		binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size);

	/* huffman_codes.c */
		int huffman_codes(char *data, size_t *freq, size_t size);


#endif
