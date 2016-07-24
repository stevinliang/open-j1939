/*
 * jlist.c Simple doubly linked list implementation
 * author: Stevin Liang <stevin_liang@163.com>
 * created: Jul 1, 2016
 *
 * This file is released under GPLv2
 *
 * This source code is simply borrowed from linux kernel.
 *
 */

#include "jlist.h"

/*
 * Insert a new entry between two consecutive entries.
 *
 * This is only for internal list manipulation where we
 * know the pre/next entries already!
 */

static void __jlist_add(struct jlist_head *new,
		struct jlist_head *prev,
		struct jlist_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;

}

void INIT_JLIST_HEAD(struct jlist_head *list)
{
	list->next = list;
	list->prev = list;
}

/**
 * jlist_add - add a new entry
 * @new: new entry to be added
 * @head: list head to add it after
 *
 * Insert a new entry after the specified head.
 * This is good for implementing stacks.
 */
void jlist_add(struct jlist_head *new, struct jlist_head *head)
{
	__jlist_add(new, head, head->next);
}

/**
 * jlist_add_tail - add new entry
 * @new: new entry to be added
 * @head: list head to add it before
 *
 * Insert a new entry before the specified head.
 * Thist is useful for implementing queues.
 */
void jlist_add_tail(struct jlist_head *new, struct jlist_head *head)
{
	__jlist_add(new, head->prev, head);
}

/*
 * Delete a list entry by making the prev/next entries
 * point to each other.
 *
 * This is only for internal list manipulation where we
 * know the pre/next entries already!
 */
static void __jlist_del(struct jlist_head *prev, struct jlist_head *next)
{
	next->prev = prev;
	prev->next = next;

}

/**
 * jlist_del - deletes entry from list.
 * @entry: the element to delete from the list.
 * Note: list_empty() on entry does not return true after this, the entry
 * is in an undefined state.
 */
void jlist_del(struct jlist_head *entry)
{
	__jlist_del(entry->prev, entry->next);
	entry->prev = NULL;
	entry->next = NULL;
}

/**
 * list_empty - tests whether a list is empty.
 * @head: the list to test
 */
int jlist_empty(struct jlist_head *head)
{
	return head->next == head;
}
