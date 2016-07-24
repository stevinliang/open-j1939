/*
 * jtypes.h  Defines base data types used in open j1939 stack.
 * author: Stevin Liang <stevin_liang@163.co>
 * created: Jun 25, 2016
 *
 * This file is released under GPLv2
 *
 */

#ifndef __JTYPES_H__
#define __JTYPES_H__

typedef unsigned char juint8_t;
typedef signed char jint8_t;

typedef unsigned short juint16_t;
typedef signed short jint16_t;

typedef unsigned int juint32_t;
typedef signed int jint32_t;

typedef signed int jsize_t;

#define	JNULL ((void *)0)

#endif
