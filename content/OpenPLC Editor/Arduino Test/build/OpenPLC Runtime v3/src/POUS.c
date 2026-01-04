void MAIN_init__(MAIN *data__, BOOL retain) {
  __INIT_VAR(data__->START_BLINK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TON0_COIL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TON1_COIL,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON0,retain);
  TON_init__(&data__->TON1,retain);
  __INIT_LOCATED(BOOL,__IX100_0,data__->BUTTONON_LED,retain)
  __INIT_LOCATED_VALUE(data__->BUTTONON_LED,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX100_1,data__->BUTTONOFF_LED,retain)
  __INIT_LOCATED_VALUE(data__->BUTTONOFF_LED,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX100_2,data__->BUTTONON_LEDBLINK,retain)
  __INIT_LOCATED_VALUE(data__->BUTTONON_LEDBLINK,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX100_3,data__->BUTTONOFF_LEDBLINK,retain)
  __INIT_LOCATED_VALUE(data__->BUTTONOFF_LEDBLINK,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX100_0,data__->LED1,retain)
  __INIT_LOCATED_VALUE(data__->LED1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX100_1,data__->LED2,retain)
  __INIT_LOCATED_VALUE(data__->LED2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX100_2,data__->LED3,retain)
  __INIT_LOCATED_VALUE(data__->LED3,__BOOL_LITERAL(FALSE))
}

// Code part
void MAIN_body__(MAIN *data__) {
  // Initialise TEMP variables

  __SET_LOCATED(data__->,LED1,,(!(__GET_LOCATED(data__->BUTTONOFF_LED,)) && (__GET_LOCATED(data__->BUTTONON_LED,) || __GET_LOCATED(data__->LED1,))));
  __SET_VAR(data__->,START_BLINK,,((!(__GET_LOCATED(data__->BUTTONOFF_LEDBLINK,)) && (__GET_LOCATED(data__->BUTTONON_LEDBLINK,) || __GET_VAR(data__->START_BLINK,))) && __GET_LOCATED(data__->LED1,)));
  __SET_VAR(data__->TON0.,IN,,(!(__GET_VAR(data__->TON1_COIL,)) && __GET_VAR(data__->START_BLINK,)));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,TON0_COIL,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->TON1.,IN,,(__GET_VAR(data__->TON0_COIL,) && __GET_VAR(data__->START_BLINK,)));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->,TON1_COIL,,__GET_VAR(data__->TON1.Q,));
  __SET_LOCATED(data__->,LED3,,(!(__GET_VAR(data__->TON0_COIL,)) && __GET_VAR(data__->START_BLINK,)));
  __SET_LOCATED(data__->,LED2,,(__GET_VAR(data__->TON0_COIL,) && __GET_VAR(data__->START_BLINK,)));

  goto __end;

__end:
  return;
} // MAIN_body__() 





