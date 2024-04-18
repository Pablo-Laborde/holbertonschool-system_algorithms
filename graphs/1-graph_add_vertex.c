#include "graphs.h"


/**
* graph_add_vertex- func
* @graph: graph_t *
* @str: const char *
* Return: vertex_t *
*/
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	size_t index = 0;
	vertex_t *vertex = NULL;

	if (graph && str)
	{
		if (graph->vertices)
			index = graph->vertices->index;
		vertex = add_rec_vertex(graph->vertices, index, str);
		if (!graph->vertices)
		{
			graph->vertices = vertex;
			graph->nb_vertices = 0;
		}
		graph->nb_vertices++;
	}
	return (vertex);
}


/**
* add_rec_vertex- func
* @vertex: vertex_t *
* @index: size_t
* @str: const char *
* Return: vertex_t *
*/
vertex_t *add_rec_vertex(vertex_t *vertex, size_t index, const char *str)
{
	if (vertex)
	{
		if (!strcmp(vertex->content, str))
			return (NULL);
		else
		{
			if (vertex->next)
				return (add_rec_vertex(vertex->next, vertex->index + 1, str));
			else
			{
				vertex->next = add_rec_vertex(vertex->next, vertex->index + 1, str);
				return (vertex->next);
			}
		}
	}
	else
		return (create_vertex(index, str));
}


/**
* create_vertex- func
* @index: size_t
* @str: const char *
* Return: vertex_t *
*/
vertex_t *create_vertex(size_t index, const char *str)
{
	vertex_t *vertex = NULL;

	vertex = malloc(sizeof(vertex_t));
	if (vertex)
	{
		vertex->index = index;
		vertex->content = strdup(str);
		vertex->nb_edges = 0;
		vertex->edges = NULL;
		vertex->next = NULL;
	}
	return (vertex);
}
