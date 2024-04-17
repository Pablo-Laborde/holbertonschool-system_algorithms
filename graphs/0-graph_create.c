#include "graphs.h"


/**
* graph_create- func
* Return: graph_T *
*/
graph_t *graph_create(void)
{
	grpah_t *graph = NULL;

	graph = malloc(sizeof(graph_t));
	if (graph)
	{
		graph->nb_vertices = 0;
		graph->vertices = NULL;
	}
	return (graph);
}
