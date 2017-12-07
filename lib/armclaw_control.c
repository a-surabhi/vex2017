#include "../include/basic_op.h"

void subtle_claw_control() {
	if (vexRT[Btn7LXmtr2] == 1 || vexRT[Btn7RXmtr2] == 1) {
		if (vexRT[Btn7LXmtr2] == 1) {
			sendToClawMotor(-1 * CLAW_MOTOR_SPEED / 2);
		} else {
			sendToClawMotor(CLAW_MOTOR_SPEED / 2);
		}
		wait1Msec(PROGRESS_INCREMENT_DURATION);
	}
}

void subtle_arm_control() {
	if (vexRT[Btn8UXmtr2] == 1 || vexRT[Btn8DXmtr2] == 1) {
		if (vexRT[Btn8UXmtr2] == 1) {
			sendToArmMotor(LIFT_MOTOR_SPEED / 2);
		} else {
			sendToArmMotor(-1 * LIFT_MOTOR_SPEED / 3);
		}
		wait1Msec(PROGRESS_INCREMENT_DURATION);
	}
}

task armClawControl() {
	int liftArmControlThreshold = 15;
	int clawControlThreshold = 10;

	while(true){
		subtle_claw_control();
		subtle_arm_control();

		int liftControlInput = vexRT[Ch2Xmtr2];
		int clawControlInput = vexRT[Ch4Xmtr2];
		if (abs(liftControlInput) > liftArmControlThreshold) {
			if (liftControlInput < 0) {
				liftControlInput /= 2;
			}
			sendToArmMotor(liftControlInput);
		} else {
			sendToArmMotor(0);
		}

		if (abs(clawControlInput) > clawControlThreshold) {
			sendToClawMotor(sgn(clawControlInput) * CLAW_MOTOR_SPEED);
		} else {
			sendToClawMotor(0);
		}
	}
}
