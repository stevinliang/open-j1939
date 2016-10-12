/*
 * debug.h debug tool abstract here.
 * author: Stevin Liang <stevin_liang@163.com>
 * created: Jul 26, 2016
 *
 *  This file is released under GPLv2
 *
 **/

#ifndef __DEBUG_H
#define __DEBUG_H


#define DBG_PR(messege)

#define DEBUG_PL   0x00000001
#define DEBUG_NL   0x00000002
#define DEBUG_NM   0x00000003
#ifdef DEBUG

#define J1939_DBG(debug, messege)				  \
	do {										  \
		if ((debug | DEBUG_PL) ||			      \
			(debug | DEBUG_NL) ||                \
			(debug | DEBUG_NM)) {			      \
			DBG_PR(messege);					  \
		}										  \
	while(0)									  \

#else
#define J1939_DBG(debug, messege)
#endif

#endif
