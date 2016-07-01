/*
 * list.h Simple doubly linked list implementation
 * author: Stevin Liang <stevin_liang@163.com>
 * created: Jun 25, 2016
 *
 * This file is released under GPLv2
 *
 * This source code is simply borrowed from linux kernel.
 *
 */

#ifndef __LIST_H__
#define __LIST_H__

#include "types.h"

struct list_head {
	struct list_head *next, *prev;
	void *member;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name)          \
	struct list_head name = LIST_HEAD_INIT(name)

/**
 * list_entry - get the struct from this entry
 * @ptr:   the list_head pointer which embeds &struct.
 * @type:  the type of the struct embedded in this list head.
 */
#define list_entry(ptr, type)                  \
	((type *)((ptr)->member))

/**
 * list_first_entry - get the first element from a list
 * @ptr:   the list head to take the element from.
 * @type:  the type of &struct embedded in the list head.
 *
 * Note, that list is expected to be not empty.
 */
#define list_first_entry(ptr, type)            \
	list_entry(ptr, type)

/**
 * list_for_each -  iterate over a list
 * @pos:    the list head to use as a loop cursor.
 * @head:   head for your list.
 */
#define list_for_each(pos, head)               \
	for (pos = (head)->next; pos != (head); pos = pos->next)

/**
 * list_for_each_entry  -  iterate over list of given type
 * @pos:   the type * to use as loop cursor.
 * @head:  the head for your list.
 * @type:  the type of struct embedded in list_head
 */
#define list_for_each_entry(pos, head, type)        \
	for (pos = list_entry((head)->next, type);      \
			&(head)->list != (head);                 \
			pos = list_entry(pos->list.next), type)


void INIT_LIST_HEAD(struct list_head *list);
void list_add(struct list_head *new, struct list_head *head);
void list_add_tail(struct list_head *new, struct list_head *head);
void list_del(struct list_head *entry);


#endif
