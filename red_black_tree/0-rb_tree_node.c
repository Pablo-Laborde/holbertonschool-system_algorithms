#include "rb_trees.h"


/**
* rb_tree_node- func
* @parent: rb_tree_t *
* @value: int
* @color: rb_color_r *
* Return: rb_tree_t *
*/
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *nn = NULL;

	nn = malloc(sizeof(rb_tree_t));
	if (nn)
	{
		nn->n = value;
		nn->parent = parent;
		nn->color = color;
		nn->left = NULL;
		nn->right = NULL;
	}
	return (nn);
}
