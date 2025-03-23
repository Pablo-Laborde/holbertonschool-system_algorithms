#include "graphs.h"


/**
* breadth_first_traverse- func
* @graph: const graph_t *
* @action: function pointer
* Return: size_t
*/
size_t breadth_first_traverse(const graph_t *graph
			, void (*action)(const vertex_t *v, size_t depth))
{
	size_t dp = 0, *nv = NULL, i = 0;
	vertex_t *vx = NULL;

	if (graph)
	{
		nv = malloc(sizeof(size_t) * graph->nb_vertices);
		if (!nv)
			return (0);
		for (; i < graph->nb_vertices; i++)
			nv[i] = 1;
		vx = graph->vertices;
		dp = rec_breadth(vx, action, nv, 0);
		free(nv);
	}
	return (dp);
}


/**
* rec_breadth- func
* @vx: vertex_t *
* @action: function pointer
* @nv: size_t *
* @dp: size_t
* Return: size_t
*/
size_t rec_breadth(vertex_t *vx
			, void (*action)(const vertex_t *v, size_t depth)
			, size_t *nv, size_t dp)
{
	size_t a = 0, b = 0;
	edge_t *aux = NULL;

	if (vx)
	{
		if (nv[vx->index])
		{
			action(vx, dp);
			nv[vx->index] = 0;
		}
		aux = vx->edges;
		while (aux)
		{
			if (nv[aux->dest->index])
				action(aux->dest, dp + 1);
			aux = aux->next;
		}
		aux = vx->edges;
		while (aux)
		{
			if (nv[aux->dest->index])
			{
				nv[aux->dest->index] = 0;
				a = rec_breadth(aux->dest, action, nv, dp + 1);
				if (a > b)
					b = a;
			}
			aux = aux->next;
		}
		return ((b > dp) ? b : dp);
	}
	return (0);
}
