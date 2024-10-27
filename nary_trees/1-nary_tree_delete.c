#include "nary_trees.h"


/**
 * nary_tree_delete- func
 * @tree: nary_tree_t *
 * Return: void
 */
void nary_tree_delete(nary_tree_t *tree)
{
	if (tree)
	{
		nary_tree_delete(tree->next);
		nary_tree_delete(tree->children);
		free(tree->content);
		free(tree);
	}
}
