#include "../include/basic_op.h"
#include "slew_control.c"

task triggerAutonomous();
void runAutonomous(bool withSlewControl);

bool _autonStarted = false;

void signalAutonCompleted() {
    writeDebugStreamLine("signal auton off");
    _autonStarted = false;
}

void checkAutonomous() {
    if (vexRT[Btn6D] == 1 && vexRT[Btn6U] == 1) {
        writeDebugStreamLine("try to trigger auton");
        if (!_autonStarted) {
            writeDebugStreamLine("starting auton");
            startTask(triggerAutonomous);
            //runAutonomous(false);
            _autonStarted = true;
        }
    } else if (vexRT[Btn6D] == 1 && vexRT[Btn6U] == 0) {
        writeDebugStreamLine("auton off");
        stopTask(triggerAutonomous);
        _autonStarted = false;
    }
}

void sendToWheelMotor(int leftSpeed, int rightSpeed) {
    motor[LF] = leftSpeed;
    motor[LB] = leftSpeed;
    motor[RF] = rightSpeed;
    motor[RB] = rightSpeed;
}

void sendToLiftMotor(int speed) {
    // motorReq[ClawLeft] = speed;
    // motorReq[ClawRight] = speed;
}

void stopBotMovement() {
    sendToWheelMotor(0, 0);
}

void rotateBot(int speed) {
    sendToWheelMotor(speed, -1 * speed);
}

void sendToLiftMotor(int speed) {

}

