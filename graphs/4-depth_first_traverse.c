#include "graphs.h"


/**
* depth_first_traverse- func
* @graph: const graph_t *
* @action: function pointer
* Return: size_t
*/
size_t depth_first_traverse(const graph_t *graph
			, void (*action)(const vertex_t *v, size_t depth))
{
	size_t dp = 0, *nv = NULL, i = 0;

	if (graph)
	{
		nv = malloc(sizeof(int) * graph->nb_vertices);
		if (!nv)
			return (0);
		for (; i < graph->nb_vertices; i++)
			nv[i] = 1;
		dp = rec_traverse(graph->vertices, action, nv, -1);
	}
	return (dp);
}


/**
* rec_traverse- func
* @vx: vertex_t *
* @action: function pointer
* @nv: size_t *
* @dp: size_t
* Return: size_t
*/
size_t rec_traverse(vertex_t *vx
			, void (*action)(const vertex_t *v, size_t depth)
			, size_t *nv, size_t dp)
{
	size_t a = 0, b = 0;
	edge_t *aux = NULL;

	if (vx)
	{
		if (nv[vx->index])
		{
			dp++;
			action(vx, dp);
			nv[vx->index] = 0;
			aux = vx->edges;
			while (aux)
			{
				a = rec_traverse(aux->dest, action, nv, dp);
				aux = aux->next;
				if (a > b)
					b = a;
			}
			return (b);
		}
	}
	return (dp);
}
