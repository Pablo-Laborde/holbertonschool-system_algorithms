#ifndef RB_TREES_H
#define RB_TREES_H


#include <stdio.h>
#include <stdlib.h>


/**
 * enum rb_color_e - Possible color of a Red-Black tree
 *
 * @RED: 0 -> Red node
 * @BLACK: 1 -> Black node
 * @DOUBLE_BLACK: 1 default
 */
typedef enum rb_color_e
{
	RED = 0,
	BLACK,
	DOUBLE_BLACK
} rb_color_t;

/**
 * struct rb_tree_s - Red-Black tree node structure
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 * @color: Color of the node (RED or BLACK)
 */
typedef struct rb_tree_s
{
	int n;
	rb_color_t color;
	struct rb_tree_s *parent;
	struct rb_tree_s *left;
	struct rb_tree_s *right;
} rb_tree_t;


/* 0-rb_tree_node.c */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color);

/* 1-rb_tree_is_valid.c */
int rb_tree_is_valid(const rb_tree_t *tree);
int rec_rbtv(const rb_tree_t *node);
int rec_bst(const rb_tree_t *node);
int rec_abn(const rb_tree_t *node);

/* 2-rb_tree_insert */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value);
rb_tree_t *rb_insert_node(rb_tree_t *node, int n);
void rb_fix_violation(rb_tree_t *node);
void rb_right_r(rb_tree_t *n);
void rb_left_r(rb_tree_t *n);
void rb_root(rb_tree_t **root, rb_tree_t *node);

/* 3-array_to_rb_tree.c */
rb_tree_t *array_to_rb_tree(int *array, size_t size);


#endif
