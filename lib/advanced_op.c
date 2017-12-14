#include "../include/basic_op.h"
#include "../include/sensor_op.h"
#include "../include/advanced_op.h"

typedef enum {
	MovementTask = 0,
	ForkPositionTask = 3,
	OrientationTask = 4
} TaskNames;

typedef enum {
	None = 0,
	Forward = 1,
	Backword = 2,
} DriveDirection;

int _wheelEncoderTargetValue;
int _forkTargetPosition;
int _orientationTarget;
int _initialOrientationPosition = 0;
DriveDirection _driveDirection = None;

bool _activeTaskList[10];

bool _isAllTaskDone() {
	for (int i=0;i<10;++i) {
		if (_activeTaskList[i]) {
			return false;
		}
	}
	return true;
}

void _completeMovementTask() {
	stopBotMovement();
	_activeTaskList[MovementTask] = false;
	_wheelEncoderTargetValue = 0;
	resetWheelEncoder();
}

void _completeForkPositionTask() {
	stopForkMovement();
	_activeTaskList[ForkPositionTask] = false;
}

void _completeOrientationTask() {
	stopBotMovement();
	_activeTaskList[OrientationTask] = false;
}

void _ensureMovementTaskDone() {
	if (_activeTaskList[MovementTask]) {
		int wheelEncoder = getWheelEncoderValue();
		if ((_wheelEncoderTargetValue > 0 && wheelEncoder > _wheelEncoderTargetValue) ||
			(_wheelEncoderTargetValue < 0 && wheelEncoder < _wheelEncoderTargetValue)) {
			_completeMovementTask();
		}
	}
}

void _ensureForkPositionTaskDone() {
	if (_activeTaskList[ForkPositionTask]) {
		int forkPosition = getForkPosition();
		int delta = forkPosition - _forkTargetPosition;
		if ((_forkTargetPosition == FORK_FLOOR_POSITION && delta > 0) || (_forkTargetPosition == FORK_CEILING_POSITION && delta < 0)) {
			_completeForkPositionTask();
		}
	}
}

void _ensureOrientationTaskDone() {
	if (_activeTaskList[OrientationTask]) {
		int currentOrientation = getOrientation();
		int delta = currentOrientation - _orientationTarget;
		if (abs(delta) > ORIENTATION_THRESHOLD) {
			int rotateSpeed = ROTATE_MOTOR_SPEED;
			if (abs(delta) <= 250) {
				rotateSpeed = ROTATE_MOTOR_SPEED_HALF;
			}
			//writeDebugStreamLine("delta = %d ,set rotation speed to %d", delta, rotateSpeed);
			rotateBot(sgn(delta) * rotateSpeed);
		} else {
			writeDebugStreamLine("complete rotation task, current position = %d, delta = %d", currentOrientation, delta);
			_completeOrientationTask();
		}
	}
}

void sync() {
	while (!_isAllTaskDone()) {
		_ensureMovementTaskDone();
		_ensureForkPositionTaskDone();
		_ensureOrientationTaskDone();

		wait1Msec(10);
	}
}

void syncAndWait(int milliseconds) {
	sync();
	wait1Msec(milliseconds);
}

void dropForkToFloor() {
	_activeTaskList[ForkPositionTask] = true;
	_forkTargetPosition = FORK_FLOOR_POSITION;
	sendToForkMotor(FORK_MOTOR_SPEED);
}

void raiseForkToCeiling() {
	_activeTaskList[ForkPositionTask] = true;
	_forkTargetPosition = FORK_CEILING_POSITION;
	sendToForkMotor(-1 * FORK_MOTOR_SPEED);
}

int _convertToEncoderValueFromDistance(float distance) {
	return distance * DISTANCE_TO_ENCODER_VALUE_BASE_FACTOR;
}

void _initiateBotMovement(int distance, DriveDirection direction) {
	resetWheelEncoder();
	_activeTaskList[MovementTask] = true;
	int encoderValue = _convertToEncoderValueFromDistance(distance);
	_initialOrientationPosition = getOrientation();
	_driveDirection = direction;

	switch(direction) {
		case Forward:
			sendToWheelMotor(WHEEL_MOTOR_SPEED, WHEEL_MOTOR_SPEED);
			_wheelEncoderTargetValue = -1 * encoderValue;
			break;
		case Backword:
			sendToWheelMotor(-1 * WHEEL_MOTOR_SPEED, -1 * WHEEL_MOTOR_SPEED);
			_wheelEncoderTargetValue = encoderValue;
			break;
	}
}

void driveForward(float distance) {
	_initiateBotMovement(distance, Forward);
}

void driveBackward(float distance) {
	_initiateBotMovement(distance, Backword);
}

void rotateClockwise(int degree) {
	degree -= 5;
	int currentSetting = SensorValue[Gyro];
	_orientationTarget = currentSetting - 10 * degree;
	_activeTaskList[OrientationTask] = true;
}

void rotateCounterClockwise(int degree) {
	degree -= 5;
	int currentSetting = SensorValue[Gyro];
	_orientationTarget = 10 * degree + currentSetting;
	_activeTaskList[OrientationTask] = true;
}
