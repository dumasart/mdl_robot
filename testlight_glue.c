#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"
#include <string.h>  /* for strlen */

#include "periods.h"

// GLUE CODE: include the Lustre generated header
#include "Controller.h"


/* OSEK specific code, DO NOT CHANGE */
DeclareCounter(SysTimerCnt);
DeclareTask(Task1);
void user_1ms_isr_type2(void) {
  StatusType ercd;
  ercd = SignalCounter(SysTimerCnt);
  /* Increment OSEK Alarm Counter */
  if(ercd != E_OK) { ShutdownOS(ercd); }
}
/* END OF OSEK specific code */

/* Init and terminate OSEK */
void ecrobot_device_initialize() {
   /* GLUE CODE:
		light sensor are ACTIVE devices and must be initialized
		(conversely to buttons, for instance)
   */
	ecrobot_set_light_sensor_active(NXT_PORT_S1);
	ecrobot_set_light_sensor_active(NXT_PORT_S2);
	ecrobot_init_sonar_sensor(NXT_PORT_S3);
	// Controller_init();
}

void ecrobot_device_terminate() {
   /* GLUE CODE:
		light sensor must be switched off
   */
	ecrobot_term_sonar_sensor(NXT_PORT_S3);
	ecrobot_set_light_sensor_inactive(NXT_PORT_S1);
	ecrobot_set_light_sensor_inactive(NXT_PORT_S2);
}



/* UsrTask */

/* GLUE CODE
	Since a SINGLE instance of teh Lustre gen. code is used,
	we can compile it using "-ctx-static" (cf. Makefile)
   making the interface simpler:
		- In particular, we don't have to "alocate" the node context:
   	the global, unique instance is declared in the generated.
		- all the "methods" (init, step input, output) have NO parameters
*/


/* GLUE CODE
	IMPORTANT !!!
	All used Lustre nodes MUST be initialized HERE
	using the procedure provided in the generated code
*/
void usr_init(void) {
	Controller_init();
}

/* GLUE CODE
	Output procedures
	Note: we directly use here the functions from
	the "ecrobot" library (display_goto_xy, display_string etc)
*/
void Controller_O_state(_boolean b){
   /* displays on 1st line */
   display_goto_xy(0,0);
   if (b) display_string("Sensor 1");
   else display_string("Sensor 2");
}
void Controller_O_val(_integer i){
   /* displays on 2nd line */
   display_goto_xy(0,1);
   display_int(i,5);
}

void show_var(char* what, int line, int var) {
	display_goto_xy(0, line);
	display_string(what);
	display_goto_xy(strlen(what)+1, line);
	display_int(var, 5);
	display_update();
}

int getLeft(int max, int min){
	// en simulink (result) 100 -> blanc 0-> noir
	int res = (max-ecrobot_get_light_sensor(NXT_PORT_S2))*100/(max-min);
	if (res < 0){
		return 0;
	}else if (res >100){
		return 100;
	}
	return res;
}

int getRight(int max, int min){
	int res = (max-ecrobot_get_light_sensor(NXT_PORT_S1))*100/(max-min);
	if (res < 0){
		return 0;
	}else if (res >100){
		return 100;
	}
	return res;
}
int getSonar(){
	// ça a l'air de marcher
	int tmp = ecrobot_get_sonar_sensor(NXT_PORT_S3);
	if (tmp < 20){
		return 0;
	}
	else {
		return 50;
	}
}
/*
	GLUE CODE
	The "core" of a step:
   - read inputs from sensors and copy them to Lustre code
     using the corresponding input procedures
	- calls the step proc.
*/
TASK(UsrTask)
{
	// initialisation des sensors

	static int init = 0;
	static int white_left = 0;
	static int white_right = 0;
	static int black_right = 0;
	static int black_left = 0;

	switch (init){
		case 0:
		// init capteur gauche et droite blanc
		display_goto_xy(0, 0);
		display_string("Put both sensors");
		display_goto_xy(0, 1);
		display_string("on WHITE");
		// show_var("G ", 5,ecrobot_get_light_sensor(NXT_PORT_S2));
		// show_var("D ", 6,ecrobot_get_light_sensor(NXT_PORT_S1));
		display_update();
		if (ecrobot_is_ENTER_button_pressed()) {
			white_right = ecrobot_get_light_sensor(NXT_PORT_S1);
			white_left = ecrobot_get_light_sensor(NXT_PORT_S2);
			init ++;
		}
		TerminateTask();
		break;

		case 1:
		if (!ecrobot_is_ENTER_button_pressed()) {
			init ++;
		}
		TerminateTask();
		break;
		case 2:
		// init capteur gauche et droite noir
		display_goto_xy(0, 0);
		display_string("Put both sensors");
		display_goto_xy(0, 1);
		display_string("on BLACK");
		// show_var("G ", 5,ecrobot_get_light_sensor(NXT_PORT_S2));
		// show_var("D ", 6,ecrobot_get_light_sensor(NXT_PORT_S1));
		display_update();
		if (ecrobot_is_ENTER_button_pressed()) {
			black_right = ecrobot_get_light_sensor(NXT_PORT_S1);
			black_left = ecrobot_get_light_sensor(NXT_PORT_S2);
			init ++;
		}
		TerminateTask();
		break;

		case 3:
		if (!ecrobot_is_ENTER_button_pressed()) {
			init ++;
		}
		TerminateTask();
		break;

		case 4:
		/* read and set inputs */
		Controller_I_Cd(getRight(black_right, white_right));
		Controller_I_Cg(getLeft(black_left, white_left));
		Controller_I_Co_n(getSonar()); // Il passe bien dans le mode demi-tour
		// mais il y reste pas
		/* performs a Lustre step
		output procs are called within the step
		*/



		Controller_step();

		/* refresh screen (ecrobot library)
		*/
		show_var("sonar real", 3, getSonar());
		show_var("sonar", 4, ecrobot_get_sonar_sensor(NXT_PORT_S3));
		show_var("Gauche ", 5,getLeft(white_left, black_left));
		show_var("Droite ", 6,getRight(white_right, black_right));
		show_var("wh lft: ", 0,white_left);
		show_var("bl lft: ", 1,black_left);
		display_update();

		TerminateTask();

		break;

		default:
		display_goto_xy(0, 0);
		display_string("Etat incorrect !");
		display_update();

		TerminateTask();
	}

}
