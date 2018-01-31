/********
* ec2c version 0.67
* context   method = STATIC
* ext call  method = PROCEDURES
* c header file generated for node : testlight 
* to be used with : testlight.c 
********/
#ifndef _testlight_EC2C_H_FILE
#define _testlight_EC2C_H_FILE
/*-------- Predefined types ---------*/
#ifndef _EC2C_PREDEF_TYPES
#define _EC2C_PREDEF_TYPES
typedef int _boolean;
typedef int _integer;
typedef char* _string;
typedef double _real;
typedef double _double;
typedef float _float;
#define _false 0
#define _true 1
#endif
/*--------- Pragmas ----------------*/
//MODULE: testlight 3 2
//IN: _boolean b
//IN: _integer c1
//IN: _integer c2
//OUT: _integer val
//OUT: _boolean state
#ifndef _testlight_EC2C_SRC_FILE
/*-------- Input procedures -------------*/
extern void testlight_I_b(_boolean);
extern void testlight_I_c1(_integer);
extern void testlight_I_c2(_integer);
/*-------- Reset procedure -----------*/
extern void testlight_reset();
/*--------Context init = context reset --------*/
#define testlight_init testlight_reset
/*-------- Step procedure -----------*/
extern void testlight_step();
#endif
#endif
