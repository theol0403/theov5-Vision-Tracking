#include "main.hpp"

//#include "DriverBaseControl.hpp"
// comp. control has not been fully implemented yet, so
// this function will never be called

void baseMotorsMove(int degreesLeft, int degreesRight)
{
	pros::Motor leftBaseMotor(1, pros::c::E_MOTOR_GEARSET_36, false);
  pros::Motor rightBaseMotor(2, pros::c::E_MOTOR_GEARSET_36, true);
	leftBaseMotor.move_relative(degreesLeft, 127);
	rightBaseMotor.move_relative(degreesRight, 127);
}



void autonomous()
{

baseMotorsMove(700, 700);
baseMotorsMove(-700, -700);

}
