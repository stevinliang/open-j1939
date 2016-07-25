#include "jqueue.h"
#include "jerrno.h"
#include "jtypes.h"

static int get_jqueue_size(struct jqueue *pq)
{
	return pq->size;
}


int is_jqueue_empty(struct jqueue *pq)
{
	if (get_jqueue_size(pq) == 0)
		return 1;
	else
		return 0;
}
int is_jqueue_full(struct jqueue *pq)
{
	if (get_jqueue_size(pq) == JQUEUE_BUF_SIZE)
		return 1;
	else
		return 0;
}


static int add_index(int index)
{
	return (index + 1) % JQUEUE_BUF_SIZE;
}

void jqueue_init(struct jqueue *pq)
{
	pq->size = 0;
	pq->head = 0;
	pq->size = 0;
	jmutex_init(&pq->lock, 0);

	return;
}

int enjqueue(struct jqueue *pq, void *item)
{
	void *buf = NULL;

	if (is_jqueue_full(pq))
		return -JENOBUFS;

	buf = pq->buf[pq->tail];

	buf = item;

	pq->tail = add_index(pq->tail);

	pq->size += 1;

	return 0;


}

int dejqueue(struct jqueue *pq, void **item)
{
	void *buf = NULL;

	if (is_jqueue_empty(pq))
		return -JEINVAL;

	buf = pq->buf[pq->head];
	pq->head = add_index(pq->head);

	*item = buf;
	pq->size -= 1;

	return 0;
}


