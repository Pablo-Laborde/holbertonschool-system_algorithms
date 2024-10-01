#include "heap.h"


/**
 * heap_extract- func
 * @heap: heap_t *
 * Return: void
 */
void *heap_extract(heap_t *heap)
{
	void *r_data = NULL;
	binary_tree_node_t *root = NULL, *last = NULL, *p = NULL;

	if (!heap)
		return (NULL);
	root = heap->root;
	last = get_last_node(root, heap->size);
	if (!last)
		return (NULL);
	r_data = root->data;
	if (root == last)
		heap->root = NULL;
	else
	{
		root->data = last->data;
		p = last->parent;
		(p->right == last) ? (p->right = NULL) : (p->left = NULL);
	}
	(heap->size)--;
	order_down(heap, root);
	free(last);
	return (r_data);
}


/**
 * get_last_node- func
 * @root: binary_tree_node_t *
 * @pos: size_t
 * Return: binary_tree_node_t *
 */
binary_tree_node_t *get_last_node(binary_tree_node_t *root, size_t pos)
{
	binary_tree_node_t *aux = NULL;

	if (!pos)
		return (NULL);
	if (pos == 1)
		return (root);
	aux = get_last_node(root, pos / 2);
	return (pos % 2) ? (aux->right) : (aux->left);
}


/**
 * order_down- func
 * @h: heap_t *
 * @node: binary_tree_node_t *
 * Return: void
 */
void order_down(heap_t *h, binary_tree_node_t *node)
{
	void *data_aux = NULL;
	binary_tree_node_t *a = NULL, *l = NULL, *r = NULL;

	if (h->data_cmp && node && node->left)
	{
		l = node->left;
		r = node->right;
		a = (r) ? ((h->data_cmp(r->data, l->data) > 0) ? l : r) : l;
		if (h->data_cmp(node->data, a->data) > 0)
		{
			data_aux = a->data;
			a->data = node->data;
			node->data = data_aux;
			order_down(h, a);
		}
	}
}
