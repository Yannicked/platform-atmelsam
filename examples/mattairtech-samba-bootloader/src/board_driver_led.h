/*
  Copyright (c) 2015 Arduino LLC.  All right reserved.
  Copyright (c) 2015 Atmel Corporation/Thibaut VIARD.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _BOARD_DRIVER_LED_
#define _BOARD_DRIVER_LED_

#include <sam.h>
#include "board_definitions.h"
#include "util.h"

#define LED_STATUS_SUCCESS                      1000
#define LED_STATUS_FILE_ALREADY_MATCHES         500
#define LED_STATUS_FILE_NOT_FOUND               250
#define LED_STATUS_NO_SAM_BA_INTERFACE          125
#define LED_STATUS_FILE_TOO_LARGE               63
#define LED_STATUS_VERIFICATION_FAILURE         31

void LED_pulse(void);
void LED_status(uint32_t periodMS);


#if defined(BOARD_LED_PORT)
  #if ((defined BOARD_LED_POLARITY) && BOARD_LED_POLARITY == LED_POLARITY_LOW_ON)
    inline void LED_on(void) { PORT->Group[BOARD_LED_PORT].OUTCLR.reg = (1<<BOARD_LED_PIN); }
    inline void LED_off(void) { PORT->Group[BOARD_LED_PORT].OUTSET.reg = (1<<BOARD_LED_PIN); }
  #else
    inline void LED_on(void) { PORT->Group[BOARD_LED_PORT].OUTSET.reg = (1<<BOARD_LED_PIN); }
    inline void LED_off(void) { PORT->Group[BOARD_LED_PORT].OUTCLR.reg = (1<<BOARD_LED_PIN); }
  #endif
  static inline void LED_init(void) { PORT->Group[BOARD_LED_PORT].DIRSET.reg = (1<<BOARD_LED_PIN); LED_off(); }
  inline void LED_toggle(void) { PORT->Group[BOARD_LED_PORT].OUTTGL.reg = (1<<BOARD_LED_PIN); }
#else
  inline void LED_init(void) { }
  inline void LED_on(void) { }
  inline void LED_off(void) { }
  inline void LED_toggle(void) { }
#endif

#if defined(BOARD_LEDRX_PORT)
  #if ((defined BOARD_LEDRX_POLARITY) && BOARD_LEDRX_POLARITY == LED_POLARITY_LOW_ON)
    inline void LEDRX_on(void) { PORT->Group[BOARD_LEDRX_PORT].OUTCLR.reg = (1<<BOARD_LEDRX_PIN); }
    inline void LEDRX_off(void) { PORT->Group[BOARD_LEDRX_PORT].OUTSET.reg = (1<<BOARD_LEDRX_PIN); }
  #else
    inline void LEDRX_on(void) { PORT->Group[BOARD_LEDRX_PORT].OUTSET.reg = (1<<BOARD_LEDRX_PIN); }
    inline void LEDRX_off(void) { PORT->Group[BOARD_LEDRX_PORT].OUTCLR.reg = (1<<BOARD_LEDRX_PIN); }
  #endif
inline void LEDRX_init(void) { PORT->Group[BOARD_LEDRX_PORT].DIRSET.reg = (1<<BOARD_LEDRX_PIN); LED_off(); }
inline void LEDRX_toggle(void) { PORT->Group[BOARD_LEDRX_PORT].OUTTGL.reg = (1<<BOARD_LEDRX_PIN); }
#else
inline void LEDRX_init(void) { }
inline void LEDRX_on(void) { }
inline void LEDRX_off(void) { }
inline void LEDRX_toggle(void) { }
#endif

#if defined(BOARD_LEDTX_PORT)
  #if ((defined BOARD_LEDTX_POLARITY) && BOARD_LEDTX_POLARITY == LED_POLARITY_LOW_ON)
    inline void LEDTX_on(void) { PORT->Group[BOARD_LEDTX_PORT].OUTCLR.reg = (1<<BOARD_LEDTX_PIN); }
    inline void LEDTX_off(void) { PORT->Group[BOARD_LEDTX_PORT].OUTSET.reg = (1<<BOARD_LEDTX_PIN); }
  #else
    inline void LEDTX_on(void) { PORT->Group[BOARD_LEDTX_PORT].OUTSET.reg = (1<<BOARD_LEDTX_PIN); }
    inline void LEDTX_off(void) { PORT->Group[BOARD_LEDTX_PORT].OUTCLR.reg = (1<<BOARD_LEDTX_PIN); }
  #endif
inline void LEDTX_init(void) { PORT->Group[BOARD_LEDTX_PORT].DIRSET.reg = (1<<BOARD_LEDTX_PIN); LED_off(); }
inline void LEDTX_toggle(void) { PORT->Group[BOARD_LEDTX_PORT].OUTTGL.reg = (1<<BOARD_LEDTX_PIN); }
#else
inline void LEDTX_init(void) { }
inline void LEDTX_on(void) { }
inline void LEDTX_off(void) { }
inline void LEDTX_toggle(void) { }
#endif

#endif // _BOARD_DRIVER_LED_