#include "rb_trees.h"


/**
* rb_tree_is_valid- func
* @tree: rb_tree_t *
* Return: int
*/
int rb_tree_is_valid(const rb_tree_t *tree)
{
	if (tree)
	{
		if (rec_rbtv(tree) && rec_bst(tree) && rec_abn(tree))
			return (1);
		else
			return (0);
	}
	return (0);
}


/**
* rec_rbtv- func
* @node: rb_tree_t *
* Return: int
*/
int rec_rbtv(const rb_tree_t *node)
{
	if (node)
		if (node->parent)
			if ((node->color == RED) && (node->parent->color == RED))
				return (0);
			else
				return (1 * rec_rbtv(node->left) * rec_rbtv(node->right));
		else
			if (node->color == BLACK)
				return (1 * rec_rbtv(node->left) * rec_rbtv(node->right));
			else
				return (0);
	else
		return (1);
}


/**
* rec_bst- func
* @node: rb_tree_t *
* Return: int
*/
int rec_bst(const rb_tree_t *node)
{
	if (node)
		if (node->left && (node->left->n > node->n))
			return (0);
		else if (node->right && (node->right->n < node->n))
			return (0);
		else
			return (1 * rec_bst(node->left) * rec_bst(node->right));
	else
		return (1);
}


/**
* rec_abn- func
* @node: rb_tree_t *
* Return: int
*/
int rec_abn(const rb_tree_t *node)
{
	int rvl, rvr;

	if (!node)
	{
		return (0);
	}
	else
	{
		rvl = rec_abn(node->left);
		rvr = rec_abn(node->right);
		if (rvl != rvr)
		{
			return (0);
		}
		else
			if (node->color == RED)
				return (rvr);
			else
				return (rvl + 1);
	}
}
