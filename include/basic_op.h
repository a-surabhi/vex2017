#ifndef __basic_op_h
#define __basic_op_h

void sendToWheelMotor(int leftSpeed, int rightSpeed);
void rotateBot(int speed);
void stopBotMovement();

void stopForkMovement();
void sendToForkMotor(int speed);

#endif
