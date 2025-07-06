#include "pathfinding.h"



#define RANGE(c, r, x, y) ((x >= c) || (y >= r) || (x < 0) || (y < 0))


/**
* inq - func
* @q: queue_t *
* @x: int
* @y: int
* Return: int
*/
int inq(queue_t *q, int x, int y)
{
	int flag = 0;
	point_t *a = NULL, *b = NULL;

	a = dequeue(q);
	if (a)
	{
		if ((x == a->x) && (y == a->y))
		{
			queue_push_front(q, a);
			return (1);
		}
		queue_push_back(q, a);
		queue_push_back(q, a);
		b = dequeue(q);
		while (b != a)
		{
			if ((x == b->x) && (y == b->y))
				flag = 1;
			queue_push_back(q, b);
			b = dequeue(q);
		}
	}
	return (flag);
}


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
* Return: int
*/
int bt(queue_t *q, int c, int r, int x, int y, char **map, int i, int j)
{
	point_t *p = NULL;

	if (RANGE(c, r, x, y) || (map[y][x] == '1') || inq(q, x, y))
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
	if (bt(q, c, r, x + 1, y, map, i, j))
		return (1);
	if (bt(q, c, r, x, y + 1, map, i, j))
		return (1);
	if (bt(q, c, r, x - 1, y, map, i, j))
		return (1);
	if (bt(q, c, r, x, y - 1, map, i, j))
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
	bt(q, cols, rows, start->x, start->y, map, target->x, target->y);
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
