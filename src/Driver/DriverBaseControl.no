#include "main.hpp"
#include "DriverBaseControl.hpp"
#include "DriverVisionTracking.hpp"



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

		if (mainController.get_digital(E_CONTROLLER_DIGITAL_X))
		{
			baseTurnBias = driverBaseAngle();
		}
		else
		{
			baseTurnBias = 0;
		}


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
