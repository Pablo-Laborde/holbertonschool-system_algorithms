#include "graphs.h"


/**
* graph_delete- func
* @graph: graph_t *
* Return: void
*/
void graph_delete(graph_t *graph)
{
	if (graph)
	{
		free_vertices(graph->vertices);
		free(graph);
	}
}


/**
* free_vertices- func
* @vl: vertex_t *
* Return: void
*/
void free_vertices(vertex_t *vl)
{
	if (vl)
	{
		free_vertices(vl->next);
		free_edges(vl->edges);
		free(vl->content);
		free(vl);
	}
}


/**
* free_edges- func
* @el: edge_t *
* Return: void
*/
void free_edges(edge_t *el)
{
	if (el)
	{
		free_edges(el->next);
		free(el);
	}
}
