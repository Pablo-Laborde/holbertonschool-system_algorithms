#ifndef GRAPHS_H
#define GRAPHS_H


/* Libraries */
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>


/* Structures */
	/**
	* enum edge_type_e - Enumerates the different types of
	* connection between two vertices
	*
	* @UNIDIRECTIONAL: The connection is made only in one way
	* @BIDIRECTIONAL: The connection is made in two ways
	*/
	typedef enum edge_type_e
	{
			UNIDIRECTIONAL = 0,
			BIDIRECTIONAL
	} edge_type_t;

	/* Define the structure temporarily for usage in the edge_t */
	typedef struct vertex_s vertex_t;

	/**
	* struct edge_s - Node in the linked list of edges for a given vertex
	* A single vertex can have many edges
	*
	* @dest: Pointer to the connected vertex
	* @next: Pointer to the next edge
	*/
	typedef struct edge_s
	{
			vertex_t    *dest;
			struct edge_s   *next;
	} edge_t;


	/**
	* struct vertex_s - Node in the linked list of vertices in the adjacency list
	*
	* @index: Index of the vertex in the adjacency list.
	* @content: Custom data stored in the vertex (here, a string)
	* @nb_edges: Number of conenctions with other vertices in the graph
	* @edges: Pointer to the head node of the linked list of edges
	* @next: Pointer to the next vertex in the adjacency linked list
	*   This pointer points to another vertex in the graph, but it
	*   doesn't stand for an edge between the two vertices
	*/
	struct vertex_s
	{
			size_t      index;
			char        *content;
			size_t      nb_edges;
			edge_t      *edges;
			struct vertex_s *next;
	};

	/**
	* struct graph_s - Representation of a graph
	* We use an adjacency linked list to represent our graph
	*
	* @nb_vertices: Number of vertices in our graph
	* @vertices: Pointer to the head node of our adjacency linked list
	*/
	typedef struct graph_s
	{
			size_t      nb_vertices;
			vertex_t    *vertices;
	} graph_t;


	/**
	* struct queue_s - linked list
	*
	* @dest: Pointer to the connected vertex
	* @next: Pointer to the next node
	*/
	typedef struct queue_s
	{
			vertex_t    *dest;
			struct queue_s   *next;
			size_t depth;
	} queue_t;


/* Functions */
graph_t *graph_create(void);

vertex_t *graph_add_vertex(graph_t *graph, const char *str);
vertex_t *add_rec_vertex(vertex_t *vertex, size_t index, const char *str);
vertex_t *create_vertex(size_t index, const char *str);

int graph_add_edge(graph_t *graph, const char *src
		, const char *dest, edge_type_t type);
vertex_t *get_vertex(vertex_t *vertex, const char *str);
edge_t *ca_edge(edge_t *list, vertex_t *dest);

void graph_delete(graph_t *graph);
void free_vertices(vertex_t *vl);
void free_edges(edge_t *el);

size_t depth_first_traverse(const graph_t *graph
		, void (*action)(const vertex_t *v, size_t depth));
size_t rec_traverse(vertex_t *vx
		, void (*action)(const vertex_t *, size_t)
		, size_t *nv, size_t dp);

/* exercise 5 */
size_t breadth_first_traverse(const graph_t *graph
	, void (*action)(const vertex_t *v, size_t depth));
queue_t *breadth_queue(vertex_t *vx, size_t *nv);
void breadth_queue_add(queue_t *q, vertex_t *vx, size_t depth);
void breadth_queue_free(queue_t *q);
size_t breadth_queue_print(queue_t *q,
	void (*action)(const vertex_t *, size_t));



#endif
