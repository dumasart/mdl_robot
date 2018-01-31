#include "Controller_ext.h"
#include "Controller.h"
#include "ecrobot_interface.h"

// Il y a un paramêtrage à avoir ici avec la vitesse, si on la multiplie pas ça
// ne bouge pas (valeur trop faible?



void Controller_O_v_d(_real v_d){
	_real vit_d = v_d * 60; // 5 or 6 min value
	ecrobot_set_motor_speed(NXT_PORT_A, vit_d);
}

void Controller_O_v_g(_real v_g){
	_real vit_g = v_g * 60; // 5 or 6 min value
	ecrobot_set_motor_speed(NXT_PORT_B, vit_g);
}
