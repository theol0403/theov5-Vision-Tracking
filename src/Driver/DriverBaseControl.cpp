#include "main.hpp"
#include "../../Include/Driver/DriverBaseControl.hpp"
#include "../../Include/Driver/DriverVisionTracking.hpp"



void driverBaseControl(void*)
{
	int controllerR_Y;
	int controllerL_X;
	int controllerR_X;
	int baseTurnBias;


	while(true)
	{
		controllerR_Y = mainController.get_analog(ANALOG_RIGHT_Y);
		controllerL_X = mainController.get_analog(ANALOG_LEFT_X);
		controllerR_X = mainController.get_analog(ANALOG_RIGHT_X);

		baseTurnBias = driverBaseAngle();

		baseRightMotors(controllerR_Y - controllerL_X - baseTurnBias);
		baseLeftMotors(controllerR_Y + controllerL_X + baseTurnBias);

		baseHMotor(controllerR_X);

		pros::delay(20);
	}
}



void baseLeftMotors(int value)
{
	leftBaseMotor.move(value);
}

void baseRightMotors(int value)
{
	rightBaseMotor.move(value);
}

void baseHMotor(int value)
{
	hBaseMotor.move(value);
}
