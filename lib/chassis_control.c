#include "../include/basic_op.h"

void subtle_movement_control() {
	// if (vexRT[Btn8U] == 1 || vexRT[Btn8D] == 1 || vexRT[Btn8L] == 1 || vexRT[Btn8R] == 1) {
	// 	if (vexRT[Btn8U] == 1) {
	// 		sendToWheelMotor(WHEEL_MOTOR_SPEED / 2, 0, 0);
	// 	} else if (vexRT[Btn8D] == 1) {
	// 		sendToWheelMotor(-1 * WHEEL_MOTOR_SPEED / 2, 0, 0);
	// 	} else if (vexRT[Btn8L] == 1) {
	// 		sendToWheelMotor(0, -1 * WHEEL_MOTOR_SPEED / 2, 0);
	// 	} else if (vexRT[Btn8R] == 1) {
	// 		sendToWheelMotor(0, WHEEL_MOTOR_SPEED / 2, 0);
	// 	}
	// 	wait1Msec(PROGRESS_INCREMENT_DURATION);
	// }
}

void subtle_rotation_control() {
	// if (vexRT[Btn7L] == 1 || vexRT[Btn7R] == 1) {
	// 	if (vexRT[Btn7L] == 1) {
	// 		rotateBot(-1 * ROTATE_MOTOR_SPEED / 2);
	// 	} else {
	// 		rotateBot(ROTATE_MOTOR_SPEED / 2);
	// 	}
	// 	wait1Msec(PROGRESS_INCREMENT_DURATION);
	// }
}


task chassisControl() {
	// int liftArmControlThreshold = 15;
	// int clawControlThreshold = 10;
	// int wheelControlThreshold = 15;

	while(true){
		subtle_rotation_control();
		subtle_movement_control();
		//checkAutonomous();

		// int rotateDirection = 0;
		// if (vexRT[Btn5D] == 1) {
		// 	rotateDirection = -1;
		// }
		// else if (vexRT[Btn5U] == 1) {
		// 	rotateDirection = 1;
		// }

		// int wheelStraightMovementInput = vexRT[Ch2];
		// int wheelSideMovementInput = vexRT[Ch1];

		// if (max(abs(wheelStraightMovementInput), abs(wheelSideMovementInput)) > wheelControlThreshold
		// 	|| rotateDirection != 0) {
		// 	sendToWheelMotor(wheelStraightMovementInput, wheelSideMovementInput, rotateDirection * ROTATE_MOTOR_SPEED);
		// } else {
		// 	stopBotMovement();
		// }
	}
}
