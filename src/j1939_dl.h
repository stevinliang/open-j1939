/*
 * j1939_dl.h j1939 data link layer head file.
 * author: Stevin Liang <stevin_liang@163.com>
 *
 *    This file is released under GPLv2
 **/

#include "j1939_dl.h"
#include "jtypes.h"

struct j1939_pdu {
	juint8_t prio;
	juint8_t edp;
	juint8_t dp;
	juint8_t pf;
	juint8_t ps;
	juint8_t sa;
	juint8_t len;
	juint8_t data[8];
};

struct j1939_pg {
	juint32_t pgn;
	juint8_t sa;
	juint16_t len;
	void *data;
};
