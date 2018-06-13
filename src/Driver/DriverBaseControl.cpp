#include "main.hpp"
#include "DriverBaseControl.hpp"



void driverBaseControl(void*)
{
	int controllerR_Y;
	int controllerL_X;
	int controllerR_X;

	while(true)
	{
		controllerR_Y = mainController.get_analog(ANALOG_RIGHT_Y);
		controllerL_X = mainController.get_analog(ANALOG_LEFT_X);
		controllerR_X = mainController.get_analog(ANALOG_RIGHT_X);



		baseRightMotors(controllerR_Y - controllerL_X);
		baseLeftMotors(controllerR_Y + controllerL_X);

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
	pros::Motor rightBaseMotor(2, pros::c::E_MOTOR_GEARSET_36, true);
	rightBaseMotor.move(value);
}

void baseHMotor(float value)
{
	pros::Motor hBaseMotor(2, pros::c::E_MOTOR_GEARSET_36, true);
	hBaseMotor.move(value);
}
