#pragma config(Sensor, in1,    Gyro,           sensorGyro)
#pragma config(Sensor, in2,    ForkPotentiometer, sensorPotentiometer)
#pragma config(Sensor, dgtl1,  Jumper1,        sensorTouch)
#pragma config(Sensor, dgtl2,  Jumper2,        sensorTouch)
#pragma config(Sensor, dgtl3,  Jumper3,        sensorTouch)
#pragma config(Sensor, dgtl4,  Jumper4,        sensorTouch)
#pragma config(Sensor, dgtl5,  Jumper5,        sensorTouch)
#pragma config(Sensor, dgtl6,  Jumper6,        sensorTouch)
#pragma config(Sensor, dgtl11, WheelEncoder, sensorQuadEncoder)
#pragma config(Motor,  port1,           CM,            tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           MGI1,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           RT_LT2,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           RB,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           RF,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           LB,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LF,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           LT_RT2,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           MGI,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          CT,            tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma DebuggerWindows("debugStream")
#pragma DebuggerWindows("vexCompetitionControl")

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

#define FORK_MOTOR_SPEED 105
#define ROTATE_MOTOR_SPEED 55
#define ROTATE_MOTOR_SPEED_HALF 28
#define LIFT_MOTOR_SPEED 120
#define LIFT_MOTOR_SPEED_HALF 40
#define LIFT_MOTOR_SPEED_THIRD 30
#define WHEEL_MOTOR_SPEED 120

#define FORK_POSITIONING_THRESHOLD 20
#define ORIENTATION_THRESHOLD 10

#define FORK_FLOOR_POSITION 3000
#define FORK_CEILING_POSITION 1120

#define DISTANCE_TO_ENCODER_VALUE_BASE_FACTOR 10.5

#define PROGRESS_INCREMENT_DURATION 80

#include "lib/basic_op.c"
#include "lib/advanced_op.c"
#include "lib/sensor_op.c"
#include "lib/chassis_control.c"
#include "autonomous/autonomous_1.c"
#include "autonomous/autonomous_2.c"
#include "autonomous/autonomous_3.c"
#include "autonomous/autonomous_testing.c"

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
    bStopTasksBetweenModes = true;
    resetGyroSensor();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*---------------------------------------------------------------------------*/

void runAutonomous(bool withSlewControl) {
    writeDebugStreamLine("entering into autonomous now");

    int jumperSetting = getJumperSetting();
    if (jumperSetting == 1) {
        autonomousProgramOne();
    } else if (jumperSetting == 2) {
        autonomousProgramTwo();
    } else if (jumperSetting == 3) {
        autonomousProgramThree();
    } else if (jumperSetting == 4) {

    } else if (jumperSetting == 5) {

    } else if (jumperSetting == 6) {

    }

    signalAutonCompleted();
}

task triggerAutonomous() {
    int jumperSetting = getJumperSetting();
    if (jumperSetting == 1) {
        autonomousProgramOne();
    } else if (jumperSetting == 2) {
        autonomousProgramTwo();
    } else if (jumperSetting == 3) {
        autonomousProgramTesting();
    } else if (jumperSetting == 4) {

    } else if (jumperSetting == 5) {

    } else if (jumperSetting == 6) {

    }

    signalAutonCompleted();
}

//speed -80
void liftArm(int speed) {
    motor[RT_LT2] = speed;
    motor[LT_RT2] = speed;
}

void stopArm() {
    motor[RT_LT2] = 0;
    motor[LT_RT2] = 0;
}

//speed 80
void botDrive(int speed) {
    motor[LF] = speed;
    motor[LB] = speed;
    motor[RF] = speed;
    motor[RB] = speed;
}

void botStop() {
    motor[LF] = 0;
    motor[LB] = 0;
    motor[RF] = 0;
    motor[RB] = 0;
}

//speed 50
void botRotate(int speed) {
    motor[LF] = speed;
    motor[LB] = speed;
    motor[RF] = -speed;
    motor[RB] = -speed;
}

//speed 80
void dropFork(int speed) {
    motor[MGI] = speed;
    motor[MGI1] = speed;
}

void stopFork() {
    motor[MGI] = 0;
    motor[MGI1]= 0;
}

//speed -127
void liftFork(int speed) {
    motor[MGI] = speed;
    motor[MGI1]= speed;
}

task autonomous()
{
    //runAutonomous(true);
//drive forward 20", lift arm, stop Arm
    liftArm(-127);
    botDrive(80);
    wait1Msec(900);
    stopArm();
    botStop();
    wait1Msec(200);
//Move MGI down
 dropFork(-88)
  wait1Msec(650);
 // botStop();
//stop bot and MGI
 stopFork();
 wait1Msec(700);
  botDrive(70);
  wait1Msec(700);
  botStop();
  wait1Msec(1000);
//Lift MGI
   liftFork(80);
   wait1Msec(2000);
//Rotate bot, bot stop
    stopFork();
    wait1Msec(1000);
    botDrive(-100);
    wait1Msec(1000);
    botRotate(60);
    wait1Msec(900);
    botStop();
    wait1Msec(200);
    botDrive(100);
    wait1Msec(500);
    botStop();
    wait1Msec(200);
    botRotate(60);
    wait1Msec(600);
    botStop();
    wait1Msec(200);
    botDrive(100);
    wait1Msec(1500);
    botStop();
    wait1Msec(200);
    dropFork(-88);
    wait1Msec(650);
    stopFork();
    wait1Msec(200);
    botDrive(120);
    wait1Msec(600);
    botStop();
    wait1Msec(200);
    botDrive(-120);
    wait1Msec(2000);
    botStop();
    wait1Msec(200);



//Drive forward
     //botDrive(60);
    //wait1Msec(1500);
//Rotate left
//Drive forward
//Drop MGI
//Drive back
   // botStop();
   // dropFork(55);
   // wait1Msec(2000);

   // stopFork();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*---------------------------------------------------------------------------*/

task usercontrol() {

    while(true) {
        //tower moves up and down with range controls
        motor[RT_LT2] = -vexRT[Ch2];
        motor[LT_RT2] = -vexRT[Ch2];

        //claw moves with buttons
        if (vexRT[Btn6D] == 1) {
            motor(CM)= -88;
        } else if(vexRT[Btn6U] == 1) {
            motor(CM) = 88;
        } else if(vexRT[Btn5D] == 1) {
            motor(CT) = -88;
        } else if(vexRT[Btn5U] == 1) {
            motor(CT) = 88;
        } else {
            //signaling no motion for claw
            motor[CM]= 0;
            motor[CT]= 0;
        }

        //mobile goal intake moves with buttons on main control
        int nospeed = 0;
        if (vexRT[Btn6UXmtr2]== 1) {
            int rotateSpeed = 55;
            motor[MGI]= rotateSpeed;
            motor[MGI1]= rotateSpeed;
        } else if (vexRT[Btn6DXmtr2] == 1) {
            int rotateSpeed = -55;
            motor[MGI]= rotateSpeed;
            motor[MGI1]= rotateSpeed;
        } else {
            motor[MGI]= nospeed;
            motor[MGI1]= nospeed;
        }

        //rotation for chassis at slower speed
        int dr_rotateSpeed = 0;
        if (vexRT[Btn5DXmtr2] == 1) {
            dr_rotateSpeed = -64;
        } else if (vexRT[Btn5UXmtr2] == 1) {
            dr_rotateSpeed = 64;
        }

        //chassis moves with range controls on main control
        motor[LF] = vexRT[Ch2Xmtr2] + vexRT[Ch1Xmtr2] + dr_rotateSpeed;
        motor[LB] = vexRT[Ch2Xmtr2] + vexRT[Ch1Xmtr2] + dr_rotateSpeed;
        motor[RF] = vexRT[Ch2Xmtr2] - vexRT[Ch1Xmtr2] + dr_rotateSpeed;
        motor[RB] = vexRT[Ch2Xmtr2] - vexRT[Ch1Xmtr2] + dr_rotateSpeed;
    }
}