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
	binary_tree_node_t *node = NULL, *parent = NULL, *rn = NULL;

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
	rn = order_heap(heap, node);
	return (rn);
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
	return ((pos % 2) ? (parent->right) : (parent->left));
}


/**
 * order_heap- func
 * @heap: heap_t *
 * @node: binary_tree_node_t *
 * Return: binary_tree_node_t *
 */
binary_tree_node_t *order_heap(heap_t *heap, binary_tree_node_t *node)
{
	void *data_aux = NULL;
	binary_tree_node_t	*n = NULL, *p = NULL;

	n = node;
	if (n)
		p = n->parent;
	if (heap->data_cmp)
		while (p && (heap->data_cmp(p->data, n->data) > 0))
		{
			data_aux = n->data;
			n->data = p->data;
			p->data = data_aux;
			n = p;
			p = n->parent;
		}
	return (n);
}
