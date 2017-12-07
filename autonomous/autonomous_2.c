#include "../include/basic_op.h"
#include "../include/advanced_op.h"

/****************************************
1. move forward, lift arm, open claw
2. move back, rotate clockwise 135 degree,
3. move forward

****************************************/
void autonomousProgramTwo() {
	raiseArmBelowFence();
	openClawToWideGrabPosition();
	//syncAndWait(100);
	wait1Msec(1200);
	rotateCounterClockwise(90);
	syncAndWait(100);

	dropArmToFloor();
	wait1Msec(600);
	driveForward(40);
	syncAndWait(100);

	closeClawToGrabObects();
	syncAndWait(100);
	closeClaw(20);

	//raiseArmToCeiling();
	moveArmToHighFencePushPosition();
	rotateClockwise(105);
	syncAndWait(200);

	//liftArm(20);

	driveForward(105);
	syncAndWait(100);

	openClawToNarrowGrabPosition();
	syncAndWait(500);
	driveBackward(15);
	syncAndWait(200);

	rotateCounterClockwise(20);
	syncAndWait(100);

	//driveTowardsRight(40);
	openClawToPushPosition();
	//raiseArmToLowFencePosition();
	//moveArmToLowFenchPushPosition();
	syncAndWait(100);
	//dropArm(20);

	driveForward(20);
	syncAndWait(200);

	driveBackward(20);
	syncAndWait(1000);
	// dropArmToFloor();
	// openClawToNarrowGrabPosition();
	// syncAndWait(100);

	// rotateClockwise(90);
	// syncAndWait(100);
}
