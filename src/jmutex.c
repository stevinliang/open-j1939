#include "jmutex.h"

void jmutex_init(struct jmutex *lock, int locked)
{
	    if (locked)
			        lock->count = 0;
		    else
				        lock->count = 1;
}

void jmutex_lock(struct jmutex *lock)
{
	    while (lock->count <= 0);

		    lock->count = 0;
}

void jmutex_unlock(struct jmutex *lock)
{
	    lock->count = 1;
}

