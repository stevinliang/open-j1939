#ifndef __JDEBUG_H
#define __JDEBUG_H


#define JDBG_PR(messege)
#define JDEBUG_PL   0x00000001
#define JDEBUG_NL   0x00000002
#define JDEBUG_NM   0x00000003
#ifdef JDEBUG

#define J1939_DBG(debug, messege)				  \
	do {										  \
		if ((debug | JDEBUG_PL) ||			      \
			(debug | JDEBUG_NL) ||                \
			(debug | JDEBUG_NM)) {			      \
			JDBG_PR(messege);					  \
		}										  \
	while(0)									  \

#else
#define J1939_DBG(debug, messege)
#endif

#endif
