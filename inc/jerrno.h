/*
 * jerrno.h  defines some error number used in this project. These error numbers
 *          are simply borrowed from linux kernel.
 * author:  Stevin <stevin_liang@163.com>
 *
 *          This file is released under GPLv2.
 *
 * */

#ifndef _JERRNO_H__
#define _JERRNO_H__
#define JEPERM        1  /* Operation not permitted */
#define JENOENT       2  /* No such file or directory */
#define JESRCH        3  /* No such process */
#define JEINTR        4  /* Interrupted system call */
#define JEIO	      5  /* I/O error */
#define JENXIO        6  /* No such device or address */
#define JE2BIG        7  /* Argument list too long */
#define JENOEXEC      8  /* Exec format error */
#define JEBADF        9  /* Bad file number */
#define JECHILD      10  /* No child processes */
#define JEAGAIN      11  /* Try again */
#define JENOMEM      12  /* Out of memory */
#define JEACCES      13  /* Permission denied */
#define JEFAULT      14  /* Bad address */
#define JENOTBLK     15  /* Block device required */
#define JEBUSY       16  /* Device or resource busy */
#define JEEXIST      17  /* File exists */
#define JEXDEV       18  /* Cross-device link */
#define JENODEV      19  /* No such device */
#define JENOTDIR     20  /* Not a directory */
#define JEISDIR      21  /* Is a directory */
#define JEINVAL      22  /* Invalid argument */
#define JENFILE      23  /* File table overflow */
#define JEMFILE      24  /* Too many open files */
#define JENOTTY      25  /* Not a typewriter */
#define JETXTBSY     26  /* Text file busy */
#define JEFBIG       27  /* File too large */
#define JENOSPC      28  /* No space left on device */
#define JESPIPE      29  /* Illegal seek */
#define JEROFS       30  /* Read-only file system */
#define JEMLINK      31  /* Too many links */
#define JEPIPE       32  /* Broken pipe */
#define JEDOM        33  /* Math argument out of domain of func */
#define JERANGE      34  /* Math result not representable */

#define JEDEADLK     35  /* Resource deadlock would occur */
#define JENOLCK      37  /* No record locks available */
#define JENOSYS      38  /* Function not implemented */
#define JENOTEMPTY   39  /* Directory not empty */


#define JEBADMSG     74  /* Not a data message */
#define JEOVERFLOW   75  /* Value too large for defined data type */
#define JENOTUNIQ    76  /* Name not unique on network */
#define JEILSEQ      84  /* Illegal byte sequence */
#define JERESTART    85  /* Interrupted system call should be restarted */

#define JESTRPIPE    86  /* Streams pipe error */
#define JEDESTADDRREQ    89  /* Destination address required */
#define JEMSGSIZE    90  /* Message too long */
#define JEPROTOTYPE  91  /* Protocol wrong type for socket */
#define JENOPROTOOPT 92  /* Protocol not available */
#define JEPROTONOSUPPORT 93  /* Protocol not supported */
#define JEPFNOSUPPORT    96  /* Protocol family not supported */
#define JEADDRINUSE  98  /* Address already in use */
#define JEADDRNOTAVAIL   99  /* Cannot assign requested address */
#define JENETDOWN    100 /* Network is down */
#define JENOBUFS     105 /* No buffer space available */
#define JETIMEDOUT   110 /* Connection timed out */
#define JEALREADY    114 /* Operation already in progress */
#define JEINPROGRESS 115 /* Operation now in progress */
#define JECANCELED   125 /* Operation Canceled */

#endif
