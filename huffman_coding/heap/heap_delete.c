#include "heap.h"


/**
 * heap_delete- func
 * @heap: heap_t *
 * @free_data: function pointer
 * Return: void
 */
void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (heap)
	{
		free_tree(heap->root, free_data);
		free(heap);
	}
}


/**
 * free_tree- func
 * @node: binary_tree_node_t *
 * @free_data: function pointer
 * Return: void
 */
void free_tree(binary_tree_node_t *node, void (*free_data)(void *))
{
	if (node)
	{
		if (free_data)
			free_data(node->data);
		free_tree(node->left, free_data);
		free_tree(node->right, free_data);
		free(node);
	}
}
