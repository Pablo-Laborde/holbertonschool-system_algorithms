#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "huffman.h"


void binary_tree_print(const binary_tree_node_t *heap, int (*print_data)(char *, void *));

/**
 * symbol_print - Prints a symbol structure
 *
 * @buffer: Buffer to print into
 * @data: Pointer to a node's data
 *
 * Return: Number of bytes written in buffer
 */
int symbol_print(char *buffer, void *data)
{
	symbol_t *symbol;
	char c;
	int length;

	symbol = (symbol_t *)data;
	c = symbol->data;
	if (c == -1)
		c = '$';
	length = sprintf(buffer, "(%c/%lu)", c, symbol->freq);
	return (length);
}


/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	char data[] = {
		'a', 'b', 'c', 'd', 'e', 'f'
	};
	size_t freq[] = {
		6, 11, 12, 13, 16, 36
	};
	size_t size = sizeof(data) / sizeof(data[0]);

	if (!huffman_codes(data, freq, size))
	{
		fprintf(stderr, "Failed to get Huffman codes\n");
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
