#include "heap.h"


/**
 * binary_tree_node- func
 * @parent: binary_tree_node_t *
 * @data: void *
 * Return: binary_tree_node_t *
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *node = NULL;

	node = malloc(sizeof(binary_tree_node_t));
	if (!node)
		return (NULL);
	node->data = data;
	node->left = NULL;
	node->right  = NULL;
	node->parent = parent;
	return (node);
}
