#include "rb_trees.h"



/**
 * rb_tree_insert - insert node
 * @tree: rb_tree head
 * @value: value to insert
 * Return: created node, NULL on failure
 */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *node = NULL;

	if (!tree)
		return (NULL);
	node = rb_insert_node(*tree, value);
	rb_root(tree, node);
	return (node);
}


/**
 * rb_insert_node - funcz
 * @node: node
 * @n: value
 * Return: node
 */
rb_tree_t *rb_insert_node(rb_tree_t *node, int n)
{
	rb_tree_t *rn = NULL;

	if (!node)
		return (rb_tree_node(NULL, n, BLACK));
	if (node->n == n)
		return (NULL);
	if (node->n > n)
	{
		if (node->left)
			rn = rb_insert_node(node->left, n);
		else
		{
			node->left = rb_tree_node(node, n, RED);
			rn = node->left;
		}
	}
	else
	{
		if (node->right)
			rn = rb_insert_node(node->right, n);
		else
		{
			node->right = rb_tree_node(node, n, RED);
			rn = node->right;
		}
	}
	return (rn);
}


/**
 * rb_fix_violation - fixes little tree after insertion
 * @node: inserted node
 */
void rb_fix_violation(rb_tree_t *node)
{
	rb_tree_t *n = node, *p = node->parent, *g = NULL, *u = NULL;

	while (p && p->color == RED)
	{
		g = p->parent;
		u = (g->right == p) ? g->left : g->right;
		if (u && u->color == RED)
		{
			p->color = BLACK;
			u->color = BLACK;
			g->color = RED;
			n = g;
			if (n)
				p = g->parent;
			continue;
		}
		if (g->right == p)
		{
			if (p->left == n)
			{
				rb_right_r(n);
				p = n;
			}
			rb_left_r(p);
		}
		else /* (g->left == p) */
		{
			if (p->right == n)
			{
				rb_left_r(n);
				p = n;
			}
			rb_right_r(p);
		}
		p->color = BLACK;
		g->color = RED;
		break;
	}
}


/**
 * rb_right_r - right rotation
 * @n: node to rotate
 */
void rb_right_r(rb_tree_t *n)
{
	rb_tree_t *b = NULL, *p = NULL, *g = NULL;

	b = n->right;
	p = n->parent;
	g = p->parent;
	if (g)
		(g->left == p) ? (g->left = n) : (g->right = n);
	n->parent = g;
	n->right = p;
	p->parent = n;
	p->left = b;
	if (b)
		b->parent = p;
}


/**
 * rb_left_r - left rotation
 * @n: node to rotate
 */
void rb_left_r(rb_tree_t *n)
{
	rb_tree_t *b = NULL, *p = NULL, *g = NULL;

	b = n->left;
	p = n->parent;
	g = p->parent;
	if (g)
		(g->left == p) ? (g->left = n) : (g->right = n);
	n->parent = g;
	n->left = p;
	p->parent = n;
	p->right = b;
	if (b)
		b->parent = p;
}


/**
 * rb_root - fixes root
 * @root: root header
 * @node: last node added
 */
void rb_root(rb_tree_t **root, rb_tree_t *node)
{
	rb_tree_t *n = node;

	if (!n)
		return;
	rb_fix_violation(node);
	while (n->parent)
		n = n->parent;
	n->color = BLACK;
	*root = n;
}
