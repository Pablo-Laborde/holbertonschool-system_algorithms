#include "nary_trees.h"



/**
 * nary_tree_diameter - func
 * @root: nary_tree_t
 * Return: size_t
 */
size_t nary_tree_diameter(nary_tree_t const *root)
{
	size_t a = 0, b = 0, aux = 0, diam = 0, sub_diam = 0, diam_aux = 0;
	nary_tree_t *node = NULL;

	if (!root)
		return (0);
	node = root->children;
	while (node)
	{
		diam_aux = nary_tree_diameter(node);
		if (diam_aux > sub_diam)
			sub_diam = diam_aux;
		aux = nodes_down(node);
		if (aux > a)
		{
			b = a;
			a = aux;
		}
		else if (aux > b)
			b = aux;
		node = node->next;
	}
	diam = a + b + 1;
	return ((diam > sub_diam) ? diam : sub_diam);
}


/**
 * nodes_down - func
 * @node: nary_tree_t *
 * Return: size_t
 */
size_t nodes_down(nary_tree_t *node)
{
	size_t max = 0, aux = 0;
	nary_tree_t *sib = NULL;

	if (!node)
		return (0);
	sib = node;
	while (sib)
	{
		aux = nodes_down(sib->children);
		if (aux > max)
			max = aux;
		sib = sib->next;
	}
	return (1 + max);
}
