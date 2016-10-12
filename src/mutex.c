/*
 * jmutex.c mutex implement
 * author: Stevin Liang <stevin_liang@163.com>
 *
 *    This file is released under GPLv2
 **/

#include "mutex.h"

void mutex_init(struct mutex *lock, int locked)
{
	if (locked)
		lock->count = 0;
	else
		lock->count = 1;
}

void mutex_lock(struct mutex *lock)
{
	while (lock->count <= 0);

	lock->count = 0;
}

void mutex_unlock(struct mutex *lock)
{
	lock->count = 1;
}

