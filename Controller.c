/********
* ec2c version 0.67
* c file generated for node : Controller 
* context   method = STATIC
* ext call  method = PROCEDURES
********/
/* This program needs external declarations */
#define _Controller_EC2C_SRC_FILE
#include "Controller.h"
/*--------
 * the following ``constants'' must be defined:
extern _real kp_teta;
extern _real ki_teta;
extern _real T;
extern _real pi;
--------*/
/*--------
Internal structure for the call
--------*/
typedef struct  {
   
   //INPUTS
   _real _Cg;
   _real _Cd;
   _real _Co_n;
   //OUTPUTS
   _real _v_d;
   _real _v_g;
   //REGISTERS
   _real M40;
   _boolean M40_nil;
   _boolean M15;
   _boolean M15_nil;
   _boolean M30;
   _boolean M30_nil;
   _boolean M23;
   _boolean M23_nil;
   _boolean M12;
   _boolean M12_nil;
   _boolean M9;
} Controller_ctx;

// Single Static Context
static Controller_ctx ctx;
/*--------
Output procedures must be defined,
Input procedures must be used:
--------*/
void Controller_I_Cg(_real V){
   ctx._Cg = V;
}
void Controller_I_Cd(_real V){
   ctx._Cd = V;
}
void Controller_I_Co_n(_real V){
   ctx._Co_n = V;
}
extern void Controller_O_v_d(_real);
extern void Controller_O_v_g(_real);
#ifdef CKCHECK
extern void Controller_BOT_v_d();
extern void Controller_BOT_v_g();
#endif
/*--------
Internal reset input procedure
--------*/
static void Controller_reset_input(){
   //NOTHING FOR THIS VERSION...
}
/*--------
Reset procedure
--------*/
void Controller_reset(){
   ctx.M40_nil = _true;
   ctx.M15_nil = _true;
   ctx.M30_nil = _true;
   ctx.M23_nil = _true;
   ctx.M12_nil = _true;
   ctx.M9 = _true;
   Controller_reset_input();
}
/*--------
Step procedure
--------*/
void Controller_step(){
//LOCAL VARIABLES
   _boolean L5;
   _boolean L8;
   _boolean L14;
   _boolean L13;
   _boolean L7;
   _boolean L4;
   _real L31;
   _real L38;
   _real L36;
   _real L45;
   _real L48;
   _real L44;
   _real L49;
   _real L35;
   _real L57;
   _boolean L56;
   _real L58;
   _real L55;
   _real L54;
   _real L61;
   _real L59;
   _real L53;
   _real L51;
   _real L34;
   _real L33;
   _real L3;
   _real L66;
   _real L65;
   _real L64;
   _real L63;
   _real L42;
   _real L41;
   _real T40;
   _boolean L22;
   _boolean L25;
   _boolean L24;
   _boolean L21;
   _boolean L20;
   _boolean L27;
   _boolean L19;
   _boolean L29;
   _boolean L18;
   _boolean L17;
   _boolean L16;
   _boolean T15;
   _boolean T30;
   _boolean T23;
   _boolean T12;
//CODE
   L5 = (ctx._Co_n < 20.000000);
   if (ctx.M9) {
      L8 = _false;
   } else {
      L8 = ctx.M12;
   }
   if (ctx.M9) {
      L14 = _false;
   } else {
      L14 = ctx.M15;
   }
   L13 = (! L14);
   L7 = (L8 && L13);
   L4 = (L5 || L7);
   L31 = (- 0.500000);
   if (ctx.M9) {
      L38 = 0.000000;
   } else {
      L38 = ctx.M40;
   }
   L36 = (ki_teta * L38);
   L45 = (pi / 200.000000);
   L48 = (ctx._Cd - ctx._Cg);
   L44 = (L45 * L48);
   L49 = (kp_teta * L44);
   L35 = (L36 + L49);
   L57 = (2.000000 * L35);
   L56 = (L57 < 0.000000);
   L58 = (- L57);
   if (L56) {
      L55 = L58;
   } else {
      L55 = L57;
   }
   L54 = (- L55);
   L61 = (ctx._Cd + ctx._Cg);
   L59 = (0.005000 * L61);
   L53 = (L54 + L59);
   L51 = (2.000000 * L53);
   L34 = (L35 + L51);
   L33 = (0.500000 * L34);
   if (L4) {
      L3 = L31;
   } else {
      L3 = L33;
   }
   Controller_O_v_d(L3);
   L66 = (- L35);
   L65 = (L66 + L51);
   L64 = (0.500000 * L65);
   if (L4) {
      L63 = 0.500000;
   } else {
      L63 = L64;
   }
   Controller_O_v_g(L63);
   L42 = (T * L44);
   L41 = (L42 + L38);
   T40 = L41;
   if (ctx.M9) {
      L22 = _false;
   } else {
      L22 = ctx.M23;
   }
   L25 = (ctx._Cd >= 80.000000);
   L24 = (L25 && L4);
   L21 = (L22 || L24);
   L20 = (L21 && L13);
   L27 = (ctx._Cd <= 10.000000);
   L19 = (L20 && L27);
   if (ctx.M9) {
      L29 = _false;
   } else {
      L29 = ctx.M30;
   }
   L18 = (L19 || L29);
   L17 = (L18 && L13);
   L16 = (L17 && L24);
   T15 = L16;
   T30 = L17;
   T23 = L20;
   T12 = L4;
   ctx.M40 = T40;
   ctx.M40_nil = _false;
   ctx.M15 = T15;
   ctx.M15_nil = _false;
   ctx.M30 = T30;
   ctx.M30_nil = _false;
   ctx.M23 = T23;
   ctx.M23_nil = _false;
   ctx.M12 = T12;
   ctx.M12_nil = _false;
   ctx.M9 = ctx.M9 && !(_true);
}
