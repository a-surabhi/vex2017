int getWheelEncoderValue() {
	return SensorValue[WheelEncoder];
}

int getForkPosition() {
	return SensorValue[ForkPotentiometer];
}

int getOrientation() {
	return SensorValue[Gyro];
}

void resetWheelEncoder() {
	SensorValue[WheelEncoder] = 0;
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
	int forkPosition = getForkPosition();
	int wheelEncoder = getWheelEncoderValue();

	writeDebugStreamLine("Gyro Sensor => %d", gyroPosition);
	writeDebugStreamLine("Fork Sensor => %d", forkPosition);
	writeDebugStreamLine("Wheel Encoder => %d", wheelEncoder);
	writeDebugStreamLine("~~~~~~~~~~~~~~~~~~~~");
	writeDebugStreamLine("");
}
