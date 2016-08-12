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
};

extern void jqueue_init(struct jqueue *pq);
extern int en_jqueue(struct jqueue *pq, void *item);
extern int de_jqueue(struct jqueue *pq, void **item);

#endif
