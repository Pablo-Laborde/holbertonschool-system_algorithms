#include "pathfinding.h"



/**
* addq - func
* @q: queue_t *
* @v: vertex_t *
*/
void addq(queue_t *q, vertex_t *v)
{
	vertex_t *a = NULL, *b = NULL;

	a = dequeue(q);
	if (a)
	{
		queue_push_back(q, a);
		while (b != a)
		{
			b = dequeue(q);
			queue_push_back(q, b);
			if (!strcmp(v->content, b->content))
				return;
		}
	}
	queue_push_back(q, v);
}


/**
* proc_edges - func
* @v: vertex_t *
* @t: vertex_t *
* @weights: unsigned int *
* @prev_list: vertex_t **
* @q: queue_t *
* Return: int
*/
int proc_edges(vertex_t *v, vertex_t *t, unsigned int *weights,
	vertex_t **prev_list, queue_t *q)
{
	edge_t *edge = v->edges;

	while (edge)
	{
		if (weights[edge->dest->index] > (weights[v->index] + edge->weight))
		{
			prev_list[edge->dest->index] = v;
			weights[edge->dest->index] = (weights[v->index] + edge->weight);
			addq(q, edge->dest);
		}
		if (edge->dest == t)
			return (1);
		edge = edge->next;
	}
	return (0);
}


/**
* vtp - func
* @q: queue_t *
* @weights: unsigned int *
* Return: vertex_t *
*/
vertex_t *vtp(queue_t *q, unsigned int *weights)
{
	vertex_t *a = NULL, *b = NULL, *c = NULL;

	a = dequeue(q);
	if (a)
	{
		c = a;
		queue_push_back(q, a);
		b = dequeue(q);
		while (b != a)
		{
			if (weights[b->index] < weights[c->index])
			{
				queue_push_back(q, c);
				c = b;
			}
			else
				queue_push_back(q, b);
			b = dequeue(q);
		}
	}
	return (c);
}


/**
* dijkstra_graph - func
* @graph: graph_t *
* @start: vertex_t const *
* @target: vertex_t const *
* Return: queue_t *
*/
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target)
{
	unsigned int *weights = NULL, rv = 0;
	vertex_t **prev_list = NULL, *node = NULL, *v = NULL;
	queue_t *solution_queue = NULL, *q = NULL;

	solution_queue = queue_create();
	q = queue_create();
	prev_list = malloc(sizeof(vertex_t) * graph->nb_vertices);
	weights = malloc(sizeof(int) * graph->nb_vertices);
	if (!solution_queue || !prev_list || !weights || !q)
		return (NULL);
	memset(prev_list, 0, graph->nb_vertices * sizeof(void *));
	memset(weights, (unsigned int)(-1), graph->nb_vertices * sizeof(int));
	weights[start->index] = 0;
	v = (vertex_t *)start;
	printf("Checking %s, distance from %s is %d\n", v->content,
			start->content, weights[v->index]);
	while (v)
	{
		if (rv)
			break;
		rv = proc_edges(v, (vertex_t *)target, weights, prev_list, q);
		v = vtp(q, weights);
		printf("Checking %s, distance from %s is %d\n", v->content,
			start->content, weights[v->index]);
	}
	if (rv)
	{
		node = (vertex_t *)target;
		while (node)
		{
			queue_push_front(solution_queue, strdup(node->content));
			node = prev_list[node->index];
		}
	}
	free(weights);
	free(prev_list);
	queue_delete(q);
	return (solution_queue);
}
