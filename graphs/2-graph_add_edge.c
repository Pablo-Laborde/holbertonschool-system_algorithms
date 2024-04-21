#include "graphs.h"


/**
* graph_add_edge- func
* @graph: graph_t *
* @src: const char *
* @dest: const char *
* @type: edge_type_t
* Return: int
*/
int graph_add_edge(graph_t *graph, const char *src
			, const char *dest, edge_type_t type)
{
	vertex_t *d = NULL, *s = NULL;

	if (graph && src && dest)
	{
		s = get_vertex(graph->vertices, src);
		d = get_vertex(graph->vertices, dest);
		if (!d || !s)
			return (0);
		s->edges = ca_edge(s->edges, d);
		if (type)
			d->edges = ca_edge(d->edges, s);
		return (1);
	}
	(void)type;
	return (0);
}


/**
* get_vertex- func
* @vertex: vertex_t *
* @str: const char *
* Return: vertex_t *
*/
vertex_t *get_vertex(vertex_t *vertex, const char *str)
{
	vertex_t *ver = vertex;

	if (ver)
	{
		while (ver)
			if (strcmp(ver->content, str))
				ver = ver->next;
			else
				break;
	}
	return (ver);
}


/**
* ca_edge- func
* @list: edge_t *
* @dest: vertex_t *
* Return: edge_t *
*/
edge_t *ca_edge(edge_t *list, vertex_t *dest)
{
	edge_t *aux = list, *nv = NULL;

	nv = malloc(sizeof(edge_t));
	if (!nv)
		return (list);
	nv->dest = dest;
	nv->next = NULL;
	if (!aux)
		return (nv);
	while (aux->next)
		aux = aux->next;
	aux->next = nv;
	return (list);
}
