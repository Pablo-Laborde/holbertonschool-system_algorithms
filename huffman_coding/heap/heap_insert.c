#include "heap.h"


/**
 * heap_insert- func
 * @heap: heap_t *
 * @data: void *
 * Return: binary_tree_node_t *
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	size_t pos = 0;
	binary_tree_node_t	*node = NULL,
						*parent = NULL;

	if (!heap || !data)
		return (NULL);
	pos = heap->size + 1;
	parent = get_parent(heap->root, pos / 2);
	node = binary_tree_node(parent, data);
	if (!node)
		return (NULL);
	if (!heap->root)
		heap->root = node;
	if (parent)
		(pos % 2) ? (parent->right = node) : (parent->left = node);
	(heap->size)++;
	order_heap(heap, node);
	return (node);
}


/**
 * get_parent- func
 * @root: binary_tree_node_t *
 * @pos: size_t
 * Return: binary_tree_node_t *
 */
binary_tree_node_t *get_parent(binary_tree_node_t *root, size_t pos)
{
	binary_tree_node_t *parent = NULL;

	if (!pos)
		return (NULL);
	if (pos == 1)
		return (root);
	parent = get_parent(root, pos / 2);
	return (pos % 2) ? (parent->right) : (parent->left);
}


/**
 * order_heap- func
 * @heap: heap_t *
 * @node: binary_tree_node_t *
 * Return: void
 */
void order_heap(heap_t *heap, binary_tree_node_t *node)
{
	binary_tree_node_t	*a = node->parent,
						*b = NULL,
						*c = node->left,
						*d = node->right;

	if (!a)
		heap->root = node;
	else if (heap->data_cmp(a->data, node->data) > 0)
	{
		node->parent = a->parent;
		if (a->left == node)
		{
			node->left = a;
			node->right = a->right;
		}
		else
		{
			node->left = a->left;
			node->right = a;
		}
		a->parent = node;
		a->left = c;
		a->right = d;
		b = node->parent;
		if (b)
		{
			if (b->left == a)
				b->left = node;
			else
				b->right = node;
		}
		order_heap(heap, node);
	}
}
