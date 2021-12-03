/* ZBOSS Zigbee software protocol stack
 *
 * Copyright (c) 2012-2020 DSR Corporation, Denver CO, USA.
 * http://www.dsr-zboss.com
 * http://www.dsr-corporation.com
 * All rights reserved.
 *
 * This is unpublished proprietary source code of DSR Corporation
 * The copyright notice does not evidence any actual or intended
 * publication of such source code.
 *
 * ZBOSS is a registered trademark of Data Storage Research LLC d/b/a DSR
 * Corporation
 *
 * Commercial Usage
 * Licensees holding valid DSR Commercial licenses may use
 * this file in accordance with the DSR Commercial License
 * Agreement provided with the Software or, alternatively, in accordance
 * with the terms contained in a written agreement between you and
 * DSR.
 */
/* PURPOSE: Header to combine osif dependent files with stack
*/

#ifndef ZB_PLATFORM_OSIF_H
#define ZB_PLATFORM_OSIF_H 1

#ifdef __IAR_SYSTEMS_ICC__
#ifndef ZB_IAR
#define ZB_IAR
#endif
#endif

#ifndef DOXYGEN

#if !defined KEIL

#define MAIN() int main(int argc, char *argv[])
#define FAKE_ARGV
#define ARGV_UNUSED ZVUNUSED(argc) ; ZVUNUSED(argv)
#define MAIN_RETURN(v) return (v)

#else

/* 04/03/2018 EE CR:MINOR Am I right this is for Keil?
   If main() returns value, why MAIN_RETURN(v) does not return?
 */
#define MAIN() int main(void)
#define FAKE_ARGV char **argv = NULL
#define ARGV_UNUSED
#define MAIN_RETURN(v)

#endif  /* KEIL */

#endif /* ndef DOXYGEN */

#include "zb_osif_nrf52.h"

#endif /* ZB_PLATFORM_OSIF_H */
