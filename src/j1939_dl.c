/*
 * j1939_dl.c j1939 data link layer abstract.
 * author: Stevin Liang <stevin_liang@163.com>
 *
 *    This file is released under GPLv2
 **/
#include <string.h>
#include "j1939_dl.h"
#include "j1939_pl.h"

uint32_t get_pgn_from_pdu(struct j1939_pdu *pdu)
{
	return (pdu->p_r_dp & 0x01) << 16 | (pdu->pf & 0xFF) << 8 | (pdu->ps);
}

void build_pdu(struct j1939_pdu *pdu, uint8_t p_r_dp,
		uint8_t pf, uint8_t ps, uint8_t sa, uint8_t *data)
{
	pdu->p_r_dp = p_r_dp;
	pdu->pf = pf;
	pdu->ps = ps;
	pdu->sa = sa;
	memcpy(pdu->data, data, 8);
}


void can_frame_to_pdu(const struct can_frame *frame, struct j1939_pdu *pdu)
{
	pdu->p_r_dp = (frame->id >> 24) & 0xff;
	pdu->pf = (frame->id >> 16) & 0xff;
	pdu->ps = (frame->id >> 8) & 0xff;
	pdu->sa = frame->id & 0xff;
	memcpy(pdu->data, frame->data, 8);
}

void pdu_to_can_frame(const struct j1939_pdu *pdu, struct can_frame *frame)
{
	frame->id = pdu->p_r_dp << 24 | pdu->pf >> 16 | pdu->ps >> 8 | pdu->sa;
	frame->dlc = 8;
	memcpy(frame->data, pdu->data, frame->dlc);
}


int32_t j1939_dl_input(struct can_frame *frame)
{
	struct j1939_pdu pdu;

	can_frame_to_pdu(frame, &pdu);

	return 0;
}

int32_t j1939_dl_output(struct j1939_pg *pg)
{
	return 0;
}

