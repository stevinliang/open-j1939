/*
 * j1939_pl.h J1939 physical abstract layer.
 * author: Stevin Liang <stevin_liang@163.com>
 * created: Jun 25, 2016
 *
 * This file is released under GPLv2
 *
 */

#ifndef __J1939_PL_H__
#define __J1939_PL_H__

#include "jtypes.h"
#include "jlist.h"

struct can_frame {
	juint32_t id;
	juint8_t ide;
	juint8_t dlc;
	juint8_t data[8];
	juint16_t crc;

};

struct can_adapter {
	struct jlist_head list;
	char *name;
	int status;
	int id;
	int (*send) (struct can_adapter *adap, struct can_frame *frame);
	int (*recv) (struct can_adapter *adap, struct can_frame *frame);
};

int can_send_frame(struct can_adapter *adap, struct can_frame *frame);
int can_recv_frame(struct can_adapter *adap, struct can_frame *frame);

struct can_adapter *can_get_adapter_by_name(char *name);
struct can_adapter *can_get_adapter_by_id(int index);

int can_register_adapter(struct can_adapter *adap);
int can_unregister_adapter(struct can_adapter *adap);

int can_open_adapter(struct can_adapter *adap);
int can_close_adapter(struct can_adapter *adap);

int can_adapter_up(struct can_adapter *adap);
int can_adapter_down(struct can_adapter *adap);


#endif
