#include "../include/basic_op.h"
#include "../include/advanced_op.h"

/****************************************
1. move forward, lift arm, open claw
2. move back, rotate clockwise 135 degree,
3. move forward

****************************************/
void autonomousProgramOne() {
	rotateClockwise(50);
	//raiseArmBelowFence();
	syncAndWait(200);

	driveForward(45);
	syncAndWait(200);

	//bdropArmToFloor();
	//wait1Msec(50);
	openClawToWideGrabPosition();
	syncAndWait(100);
	closeClawToGrabObects();
	syncAndWait(200);

	moveArmToHighFencePushPosition();
	//driveForward(40);
	//syncAndWait(200);

	rotateCounterClockwise(35);	
	syncAndWait(200);
	liftArm(30);

	driveForward(70);
	wait1Msec(1000);
	raiseArmToCeiling();
	syncAndWait(200);

	openClawToWideGrabPosition();
	stopArmMovement();
	syncAndWait(1000);
	//wait1Msec(500);
	driveBackward(15);
	syncAndWait(100);

	rotateCounterClockwise(25);

	//moveArmToLowFenchPushPosition();
	//sync();
	//moveArmToLowFenchPushPosition();
	openClawToPushPosition();
	// dropArm(13);
	// wait1Msec(120);
	// stopArmMovement();  
	syncAndWait(100);
	//driveTowardsLeft(25);

	driveForward(25);
	syncAndWait(200);

	driveBackward(50);
	wait1Msec(1000);
	dropArmToFloor();
	openClawToNarrowGrabPosition();
	syncAndWait(100);

	rotateClockwise(90);
	syncAndWait(100);
}
