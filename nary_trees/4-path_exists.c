#include "nary_trees.h"


/**
 * path_exists- func
 * @root: nary_tree_t const *
 * @path: char const * const *
 * Return: int
 */
int path_exists(nary_tree_t const *root, char const * const *path)
{
	if (!root || !path)
		return (0);
	return (cp(root, path));
}


/**
 * cp- func
 * @root: nary_tree_t const *
 * @path: char const * const *
 * Return: int
 */
int cp(nary_tree_t const *root, char const * const *path)
{
	if (!path[0])
		return (1);
	if (!root)
		return (0);
	if (strcmp(root->content, path[0]))
		return (cp(root->next, path));
	else
		return (cp(root->children, path + 1));
}
