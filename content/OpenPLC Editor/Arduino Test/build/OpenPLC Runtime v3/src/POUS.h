#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

// PROGRAM MAIN
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,START_BLINK)
  __DECLARE_VAR(BOOL,TON0_COIL)
  __DECLARE_VAR(BOOL,TON1_COIL)
  TON TON0;
  TON TON1;
  __DECLARE_LOCATED(BOOL,BUTTONON_LED)
  __DECLARE_LOCATED(BOOL,BUTTONOFF_LED)
  __DECLARE_LOCATED(BOOL,BUTTONON_LEDBLINK)
  __DECLARE_LOCATED(BOOL,BUTTONOFF_LEDBLINK)
  __DECLARE_LOCATED(BOOL,LED1)
  __DECLARE_LOCATED(BOOL,LED2)
  __DECLARE_LOCATED(BOOL,LED3)

} MAIN;

void MAIN_init__(MAIN *data__, BOOL retain);
// Code part
void MAIN_body__(MAIN *data__);
#endif //__POUS_H
