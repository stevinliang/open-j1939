/*
 * jqueue.h queue implement head file.
 * author: Stevin Liang <stevin_liang@163.com>
 *
 *   This file is released under GPLv2
 **/

#ifndef __QUEUE_H
#define __QUEUE_H
#include "jtypes.h"
#define QUEUE_BUF_SIZE 16

struct queue
{
	void *buf[QUEUE_BUF_SIZE];
	int head;
	int tail;
};

extern void queue_init(struct queue *pq);
extern int en_queue(struct queue *pq, void *item);
extern int de_queue(struct queue *pq, void **item);

#endif
