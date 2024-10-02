#include "huffman.h"


/**
 * huffman_tree- func
 * @data: char *
 * @freq: size_t *
 * @size: size_t
 * Return: binary_tree_node *
 */
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size)
{
    binary_tree_node_t *rn = NULL;
    heap_t *priority_queue = NULL;

    priority_queue = huffman_priority_queue(data, freq, size);
    if (!priority_queue)
        return (NULL);
    while (priority_queue->size > 1)
        if (!huffman_extract_and_insert(priority_queue))
            return (NULL);
    rn = priority_queue->root->data;
    heap_delete(priority_queue, NULL);
    return (rn);
}
