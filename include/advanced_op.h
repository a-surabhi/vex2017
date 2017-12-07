#ifndef __advanced_op_h
#define __advanced_op_h

void dropLiftToFloor();
void raiseLiftToCeiling();

void driveForward(float distance);
void driveBackward(float distance);

void rotateClockwise(int degree);
void rotateCounterClockwise(int degree);

//wait for wheel, arm, claw command operation to finish
void sync();
//sync() plus a waiting period after sync.
void syncAndWait(int milliseconds);

#endif
