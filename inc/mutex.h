/*
 * mutex.h mutex head file.
 * author: Stevin Liang <stevin_liang@163.com>
 *
 *   This file is released under GPLv2
 **/

#ifndef _MUTEX_H
#define _MUTEX_H

struct mutex
{
	int count;
};

extern void mutex_init(struct mutex *lock, int locked);

extern void mutex_lock(struct mutex *lock);

extern void mutex_unlock(struct mutex *lock);

#endif
