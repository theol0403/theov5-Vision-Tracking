#include "main.hpp"
#include "DriverBaseControl.hpp"
#include "DriverVisionTracking.hpp"



void driverBaseControl(void*)
{
	pros::Controller mainController(CONTROLLER_MASTER);
	int controllerR_Y;
	int controllerL_X;
	int controllerR_X;
	float baseTurnBias;
	float baseForwardBias;

	while(true)
	{
		controllerR_Y = mainController.get_analog(ANALOG_RIGHT_Y);
		controllerL_X = mainController.get_analog(ANALOG_LEFT_X);
		controllerR_X = mainController.get_analog(ANALOG_RIGHT_X);

		if (mainController.get_digital(E_CONTROLLER_DIGITAL_DOWN))
		{
			baseTurnBias = driverBaseAngle();
			baseForwardBias = driverBaseForward();
		}
		else
		{
			baseTurnBias = 0;
			baseForwardBias = 0;
		}


		baseRightMotors(controllerR_Y - controllerL_X - baseTurnBias - baseForwardBias);
		baseLeftMotors(controllerR_Y + controllerL_X + baseTurnBias - baseForwardBias);

		baseHMotor(controllerR_X);

		pros::delay(10);
	}
}



void baseLeftMotors(float value)
{
	pros::Motor leftBaseMotor(1, pros::c::E_MOTOR_GEARSET_36, false);
	leftBaseMotor.move(value);
}

void baseRightMotors(float value)
{
	pros::Motor rightBaseMotor(5, pros::c::E_MOTOR_GEARSET_36, true);
	rightBaseMotor.move(value);
}

void baseHMotor(float value)
{
	pros::Motor hBaseMotor(2, pros::c::E_MOTOR_GEARSET_36, true);
	hBaseMotor.move(value);
}
