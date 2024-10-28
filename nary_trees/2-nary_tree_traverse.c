#include "nary_trees.h"


/**
 * nary_tree_traverse- func
 * @root: nary_tree_t const *
 * @action: func poin
 * Return: size_t
 */
size_t nary_tree_traverse(nary_tree_t const *root,
				void (*action)(nary_tree_t const *node, size_t depth))
{
	if (!root || !action)
		return (0);
	return (ntt(root, 0, action));
}



/**
 * ntt- func
 * @root: nary_tree_t const *
 * @d: size_t
 * @action: func poin
 * Return: size_t
 */
size_t ntt(nary_tree_t const *root, size_t d,
				void (*action)(nary_tree_t const *node, size_t depth))
{
	size_t a = 0, b = 0;

	if (!root)
		return (0);
	action(root, d);
	a = ntt(root->children, d + 1, action);
	b = ntt(root->next, d, action);
	return ((a < b) ? (b + 1) : (a + 1));
}
