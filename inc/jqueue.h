/*
 * jqueue.h queue implement head file.
 * author: Stevin Liang <stevin_liang@163.com>
 *
 *   This file is released under GPLv2
 **/

#ifndef __JQUEUE_H
#define __JQUEUE_H
#include "jtypes.h"
#define JQUEUE_BUF_SIZE 16


struct jqueue
{
	void *buf[JQUEUE_BUF_SIZE];
	int head;
	int tail;
	int size;
};

extern void jqueue_init(struct jqueue *pq);
extern int enjqueue(struct jqueue *pq, void *item);
extern int dejqueue(struct jqueue *pq, void **item);
extern int is_jqueue_empty(struct jqueue *pq);
extern int is_jqueue_full(struct jqueue *pd);


#endif
