/*
 * j1939_pl.c J1939 physical abstract layer.
 * author: Stevin Liang <stevin_liang@163.com>
 * created: Jun 25, 2016
 *
 * This file is released under GPLv2
 *
 */
#include <string.h>
#include "jerrno.h"
#include "j1939_pl.h"

JLIST_HEAD(can_adapter_list);

int can_send_frame(struct can_adapter *adap, struct can_frame *frame)
{
	adap->send(adap, frame);
}

int can_recv_frame(struct can_adapter *adap, struct can_frame *frame)
{
	adap->recv(adap, frame);
}

struct can_adapter *can_get_adapter_by_name(char *name)
{
	struct can_adapter *can_adap = NULL;

	jlist_for_each_entry(can_adap, &can_adapter_list, struct can_adapter, list) {
		if (!strcmp(can_adap->name, name))
			break;
	}

	return can_adap;
}

struct can_adapter *can_get_adapter_by_id(int index)
{
	struct can_adapter *can_adap = NULL;

	jlist_for_each_entry(can_adap, &can_adapter_list, struct can_adapter, list) {
		if (can_adap->id == index)
			break;
	}

	return can_adap;

}

int can_register_adapter(struct can_adapter *adap)
{
	struct can_adapter *pos = NULL;

	jlist_for_each_entry(pos, &can_adapter_list, struct can_adapter, list) {
		if (pos->id == adap->id)
			return -1;
	}

	jlist_add(&adap->list, &can_adapter_list);

	return 0;
}

int can_unregister_adapter(struct can_adapter *adap)
{
	jlist_del(&adap->list);
}

int can_open_adaper(struct can_adapter *adap)
{
	int ret = 0;

	if (adap->open)
		ret = adap->open(adap);
	if (ret)
		return ret;

	adap->status |= CAN_ADAPTER_OPEN_MASK;
	adap->ref ++;

	return 0;
}

int can_close_adapter(struct can_adapter *adap)
{
	int ret = 0;

	if (!(adap->status & CAN_ADAPTER_OPEN_MASK))
		return -JEINVAL;
	adap->ref --;
	if (adap->ref == 0)
		adap->status &= ~CAN_ADAPTER_OPEN_MASK;

	return 0;

}

int can_adapter_up(struct can_adapter *adap)
{

}

int can_adapter_down(struct can_adapter *adap)
{

}

