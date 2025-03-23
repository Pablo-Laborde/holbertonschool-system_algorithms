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
	queue_t *q = NULL;

	if (graph)
	{
		nv = malloc(sizeof(size_t) * graph->nb_vertices);
		if (!nv)
			return (0);
		for (; i < graph->nb_vertices; i++)
			nv[i] = 1;
		q = breadth_queue(graph->vertices, nv);
		dp = breadth_queue_print(q, action);
		breadth_queue_free(q);
		free(nv);
	}
	return (dp);
}


/**
 * breadth_queue - func
 * @vx: vertex
 * @nv: size_t *
 * Return: queue
 */
queue_t *breadth_queue(vertex_t *vx, size_t *nv)
{
	size_t depth = 0;
	queue_t *q = NULL, *a = NULL;
	edge_t *e = NULL;

	if (!vx)
		return (NULL);
	q = malloc(sizeof(queue_t));
	if (!q)
		return (NULL);
	q->dest = vx;
	q->depth = depth;
	q->next = NULL;
	nv[vx->index] = 0;
	a = q;
	while (a)
	{
		e = a->dest->edges;
		while (e)
		{
			if (nv[e->dest->index])
			{
				breadth_queue_add(a, e->dest, a->depth + 1);
				nv[e->dest->index] = 0;
			}
			e = e->next;
		}
		a = a->next;
	}
	return (q);
}


/**
 * breadth_queue_add - func
 * @q: queue list
 * @vx: vertex
 * @depth: depth
 */
void breadth_queue_add(queue_t *q, vertex_t *vx, size_t depth)
{
	if (!q->next)
	{
		q->next = malloc(sizeof(queue_t));
		if (!q->next)
			return;
		q->next->dest = vx;
		q->next->depth = depth;
		q->next->next = NULL;
	}
	else
		breadth_queue_add(q->next, vx, depth);
}


/**
 * breadth_queue_free - func
 * @q: queue list
 */
void breadth_queue_free(queue_t *q)
{
	if (!q)
		return;
	breadth_queue_free(q->next);
	free(q);
}


/**
 * breadth_queue_print - func
 * @q: queue list
 * @action: func pointer
 * Return: depth
 */
size_t breadth_queue_print(queue_t *q,
	void (*action)(const vertex_t *, size_t))
{
	size_t a = 0, b = 0;

	if (q)
	{
		action(q->dest, q->depth);
		a = breadth_queue_print(q->next, action);
		b = (q->depth > a) ? q->depth : a;
	}
	return (b);
}
