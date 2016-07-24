/*
 * jlist.h Simple doubly linked list implementation
 * author: Stevin Liang <stevin_liang@163.com>
 * created: Jun 25, 2016
 *
 * This file is released under GPLv2
 *
 * This source code is simply borrowed from linux kernel.
 *
 */

#ifndef __JLIST_H__
#define __JLIST_H__

#include "Jtypes.h"

struct jlist_head {
	struct jlist_head *next, *prev;
	void *mem;
};

#define JLIST_HEAD_INIT(name) { &(name), &(name) }

#define JLIST_HEAD(name)          \
	struct jlist_head name = JLIST_HEAD_INIT(name)

/**
 * jlist_entry - get the struct from this entry
 * @ptr:   the list_head pointer which embeds &struct.
 * @type:  the type of the struct embedded in this list head.
 * @member: the name of the list struct within the struct.
 */
#define jlist_entry(ptr, type, member)                  \
	((type *)((ptr)->mem))

/**
 * jlist_first_entry - get the first element from a list
 * @ptr:   the list head to take the element from.
 * @type:  the type of &struct embedded in the list head.
 * @member: the name of the list struct within the struct.
 *
 * Note, that list is expected to be not empty.
 */
#define jlist_first_entry(ptr, type, member)            \
	jlist_entry(ptr, type, member)

/**
 * jlist_for_each -  iterate over a list
 * @pos:    the list head to use as a loop cursor.
 * @head:   head for your list.
 */
#define jlist_for_each(pos, head)               \
	for (pos = (head)->next; pos != (head); pos = pos->next)

/**
 * jlist_for_each_entry  -  iterate over list of given type
 * @pos:   the type * to use as loop cursor.
 * @head:  the head for your list.
 * @type:  the type of struct embedded in list_head.
 * @member: the name of the list struct within the struct
 */
#define jlist_for_each_entry(pos, head, type, member)        \
	for (pos = list_entry((head)->next, type, member);      \
			&pos->member != (head);		                    \
			pos = jlist_entry(pos->member.next, type, member))


void INIT_JLIST_HEAD(struct jlist_head *list);
void jlist_add(struct jlist_head *new, struct jlist_head *head);
void jlist_add_tail(struct jlist_head *new, struct jlist_head *head);
void jlist_del(struct jlist_head *entry);


#endif
