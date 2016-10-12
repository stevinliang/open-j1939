/*
 * j1939_dl.h j1939 data link layer head file.
 * author: Stevin Liang <stevin_liang@163.com>
 *
 *    This file is released under GPLv2
 **/
#ifndef __J1939_DL_H
#define __J1939_DL_H
#include "jtypes.h"
#include "j1939_pl.h"
struct j1939_pdu {
	uint8_t p_r_dp;
	uint8_t pf;
	uint8_t ps;
	uint8_t sa;
	uint8_t data[8];
};

struct j1939_pg {
	uint32_t pgn;
	uint8_t sa;
	uint16_t len;
	void *data;
};

uint32_t get_pgn_from_pdu(struct j1939_pdu *pdu);

void build_pdu(struct j1939_pdu *pdu, uint8_t p_r_dp,
		uint8_t pf, uint8_t ps,uint8_t sa, uint8_t *data);

int32_t j1939_dl_input(struct can_frame *frame);
void j1939_dl_init(void);

#endif
