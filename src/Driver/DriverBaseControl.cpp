#include "main.hpp"
#include "DriverBaseControl.hpp"
#include "DriverVisionTracking.hpp"



void driverBaseControl(void*)
{
	int controllerR_Y;
	int controllerL_X;
	int controllerR_X;
	float baseTurnBias;


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



void baseLeftMotors(float value)
{
	pros::Motor leftBaseMotor(1, pros::c::E_MOTOR_GEARSET_36, false);
	leftBaseMotor.move_voltage(value * 100);
}

void baseRightMotors(float value)
{
	pros::Motor rightBaseMotor(5, pros::c::E_MOTOR_GEARSET_36, true);
	rightBaseMotor.move_voltage(value * 100);
}

void baseHMotor(float value)
{
	pros::Motor hBaseMotor(2, pros::c::E_MOTOR_GEARSET_36, true);
	hBaseMotor.move(value);
}
