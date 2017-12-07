int getWheelEncoderValue() {
	// return SensorValue[RightWheelEncoder];
}

int getLiftArmPosition() {
	// return SensorValue[ArmPotentiometer];
}

int getOrientation() {
	return SensorValue[Gyro];
}

void resetWheelEncoder() {
	// SensorValue[RightWheelEncoder] = 0;
}

int getJumperSetting() {
	int jumperSetting
		= SensorValue[Jumper1] + SensorValue[Jumper2] + SensorValue[Jumper3] + SensorValue[Jumper4] + SensorValue[Jumper5] + SensorValue[Jumper6];
	return jumperSetting;
}

void resetGyroSensor() {
	 //Completely clear out any previous sensor readings by setting the port to "sensorNone"
	 SensorType[Gyro] = sensorNone;
	 wait1Msec(1000);
	 //Reconfigure Analog Port 8 as a Gyro sensor and allow time for ROBOTC to calibrate it
	 SensorType[Gyro] = sensorGyro;
	 wait1Msec(2000);
	 SensorScale[Gyro] = 98;
}

void printSensorValuesToDebugWindow() {
	int gyroPosition = getOrientation();
	int armPosition = getArmPosition();
	int clawPosition = getClawPosition();
	int rightEncoder = getRightWheelEncoderValue();

	writeDebugStreamLine("Gyro Sensor => %d", gyroPosition);
	writeDebugStreamLine("Arm Sensor => %d", armPosition);
	writeDebugStreamLine("Claw Sensor => %d", clawPosition);
	writeDebugStreamLine("Right Encoder => %d", rightEncoder);
	writeDebugStreamLine("~~~~~~~~~~~~~~~~~~~~");
	writeDebugStreamLine("");
}
