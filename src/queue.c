/*
 * queue.c queue implement.
 * author: Stevin Liang <stevin_liang@163.com>
 *
 *      This file is released under GPLv2
 **/

#include "queue.h"
#include "jerrno.h"
#include "jtypes.h"


static int is_queue_empty(struct queue *pq)
{
	if (pq->head == pq->tail)
		return 1;
	else
		return 0;
}

static int is_queue_full(struct queue *pq)
{
	if (pq->head == (pq->tail + 1) % QUEUE_BUF_SIZE)
		return 1;
	else
		return 0;
}


static int add_index(int index)
{
	return (index + 1) % QUEUE_BUF_SIZE;
}

void queue_init(struct queue *pq)
{
	pq->tail = 0;
	pq->head = 0;

	return;
}

int en_queue(struct queue *pq, void *item)
{
	void *buf = NULL;

	if (is_queue_full(pq))
		return -JENOBUFS;

	buf = pq->buf[pq->tail];

	buf = item;

	pq->tail = add_index(pq->tail);


	return 0;
}

int de_queue(struct queue *pq, void **item)
{
	void *buf = NULL;

	if (is_queue_empty(pq))
		return -JEINVAL;

	buf = pq->buf[pq->head];
	pq->head = add_index(pq->head);

	*item = buf;

	return 0;
}


