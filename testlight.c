/********
* ec2c version 0.67
* c file generated for node : testlight 
* context   method = STATIC
* ext call  method = PROCEDURES
********/
#define _testlight_EC2C_SRC_FILE
#include "testlight.h"
/*--------
Internal structure for the call
--------*/
typedef struct  {
   
   //INPUTS
   _boolean _b;
   _integer _c1;
   _integer _c2;
   //OUTPUTS
   _integer _val;
   _boolean _state;
   //REGISTERS
   _boolean M9;
   _boolean M9_nil;
   _boolean M6;
} testlight_ctx;

// Single Static Context
static testlight_ctx ctx;
/*--------
Output procedures must be defined,
Input procedures must be used:
--------*/
void testlight_I_b(_boolean V){
   ctx._b = V;
}
void testlight_I_c1(_integer V){
   ctx._c1 = V;
}
void testlight_I_c2(_integer V){
   ctx._c2 = V;
}
extern void testlight_O_val(_integer);
extern void testlight_O_state(_boolean);
#ifdef CKCHECK
extern void testlight_BOT_val();
extern void testlight_BOT_state();
#endif
/*--------
Internal reset input procedure
--------*/
static void testlight_reset_input(){
   //NOTHING FOR THIS VERSION...
}
/*--------
Reset procedure
--------*/
void testlight_reset(){
   ctx.M9_nil = _true;
   ctx.M6 = _true;
   testlight_reset_input();
}
/*--------
Step procedure
--------*/
void testlight_step(){
//LOCAL VARIABLES
   _boolean L5;
   _boolean L4;
   _integer L3;
   _boolean T9;
//CODE
   if (ctx.M6) {
      L5 = _false;
   } else {
      L5 = ctx.M9;
   }
   L4 = (ctx._b != L5);
   if (L4) {
      L3 = ctx._c1;
   } else {
      L3 = ctx._c2;
   }
   testlight_O_val(L3);
   testlight_O_state(L4);
   T9 = L4;
   ctx.M9 = T9;
   ctx.M9_nil = _false;
   ctx.M6 = ctx.M6 && !(_true);
}
