#include "pathfinding.h"



/**
* viq - func
* @q: queue_t *
* @city: char *
* Return: int
*/
int viq(queue_t *q, char *city)
{
	int flag = 0;
	char *a = NULL, *b = NULL;

	a = dequeue(q);
	if (a)
	{
		if (!strcmp(a, city))
		{
			queue_push_front(q, a);
			return (1);
		}
		queue_push_back(q, a);
		queue_push_back(q, a);
		b = dequeue(q);
		while (b != a)
		{
			if (!strcmp(b, city))
				flag = 1;
			queue_push_back(q, b);
			b = dequeue(q);
		}
	}
	return (flag);
}


/**
* btg - func
* @q: queue_t *
* @s: vertex_t *
* @t: vertex_t *
* Return: int
*/
int btg(queue_t *q, vertex_t *v, vertex_t *t)
{
	char *city = NULL;
	edge_t *edge = NULL;

	if (viq(q, v->content))
		return (0);
	city = strdup(v->content);
	printf("Checking %s\n", city);
	queue_push_front(q, (void *)city);
	if (!strcmp(t->content, city))
		return (1);
	edge = v->edges;
	while (edge)
	{
		if (btg(q, edge->dest, t))
			return (1);
		edge = edge->next;
	}
	dequeue(q);
	free(city);
	return (0);
}


/**
* backtracking_graph - func
* @grapth: graph_t *
* @start: vertex_t const *
* @taget: vertex_t const *
* Return: queue_t *
*/
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target)
{
	point_t *p = NULL;
	queue_t *q = NULL, *rq = NULL;

	(void)graph;
	q = queue_create();
	if (!q)
		return (NULL);
	if (btg(q, (vertex_t *)start, (vertex_t *)target))
	{
		rq = queue_create();
		if (!rq)
			return (NULL);
		p = dequeue(q);
		while (p)
		{
			queue_push_front(rq, p);
			p = dequeue(q);
		}
	}
	queue_delete(q);
	return (rq);
}
