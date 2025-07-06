#include "pathfinding.h"



#define RANGE(c, r, x, y) ((x >= c) || (y >= r) || (x < 0) || (y < 0))


/**
* bt - func
* @q: queue_t *
* @c: int
* @r: int
* @x: int
* @y: int
* @map: char **
* @i: int
* @j: int
* @w: int
* Return: int
*/
int bt(queue_t *q, int c, int r, int x, int y, char **map, int i, int j, int w)
{
	point_t *p = NULL;

	if (RANGE(c, r, x, y) || (map[y][x] == '1'))
		return (0);
	printf("Checking coordinates [%d, %d]\n", x, y);
	p = malloc(sizeof(point_t));
	if (!p)
		exit(1);
	p->x = x;
	p->y = y;
	queue_push_front(q, (void *)p);
	if ((x == i) && (y == j))
		return (1);
	if ((w != 'r') && bt(q, c, r, x + 1, y, map, i, j, 'l'))
		return (1);
	if ((w != 'b') && bt(q, c, r, x, y + 1, map, i, j, 'u'))
		return (1);
	if ((w != 'l') && bt(q, c, r, x - 1, y, map, i, j, 'r'))
		return (1);
	if ((w != 'u') && bt(q, c, r, x, y - 1, map, i, j, 'b'))
		return (1);
	dequeue(q);
	free(p);
	return (0);
}


/**
* backtracking_array - func
* @map: char **
* @rows: int
* @cols: int
* @start: point_t const *
* @target: point const *
* Return: queue_t *
*/
queue_t *backtracking_array(char **map, int rows, int cols, point_t const
	*start, point_t const *target)
{
	point_t *p = NULL;
	queue_t *q = NULL, *rq = NULL;

	q = queue_create();
	if (!q)
		return (NULL);
	bt(q, cols, rows, start->x, start->y, map, target->x, target->y, 0);
	rq = queue_create();
	if (!rq)
		return (NULL);
	p = dequeue(q);
	while (p)
	{
		queue_push_front(rq, p);
		p = dequeue(q);
	}
	queue_delete(q);
	return (rq);
}
