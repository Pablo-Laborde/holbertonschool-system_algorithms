#include "huffman.h"


/**
 * huffman_codes - func
 * @data: char *
 * @freq: size_t *
 * @size: size_t
 * Return: int
 */
int huffman_codes(char *data, size_t *freq, size_t size)
{
	size_t pos = 3;
	char *buffer = NULL;
	binary_tree_node_t *node = NULL;

	node = huffman_tree(data, freq, size);
	if (!node)
		return (0);
	buffer = malloc(sizeof(char) * (size + 4));
	if (!buffer)
		return (0);
	memset(buffer, 0, size + 4);
	buffer[1] = ':';
	buffer[2] = ' ';
	decode_tree(node, buffer, pos);
	free_tree(node, free_symbol);
	free(buffer);
	return (1);
}


/**
 * is_leaf- func
 * @node: binary_tree_node_t
 * Return: int
 */
int is_leaf(binary_tree_node_t *node)
{
	if (node && !node->left && !node->right)
		return (1);
	return (0);
}


/**
 * decode_tree- func
 * @node: binary_tree_node_t *
 * @buffer: char *
 * @pos: size_t
 * Return: void
 */
void decode_tree(binary_tree_node_t *node, char *buffer, size_t pos)
{
	symbol_t *sym = NULL;

	if (is_leaf(node))
	{
		sym = (symbol_t *)node->data;
		buffer[0] = sym->data;
		printf("%s\n", buffer);
	}
	else
	{
		buffer[pos] = '0';
		decode_tree(node->left, buffer, pos + 1);
		buffer[pos] = '1';
		decode_tree(node->right, buffer, pos + 1);
	}
}
