#include "main.hpp"

//#include "DriverBaseControl.hpp"
// comp. control has not been fully implemented yet, so
// this function will never be called

void baseMotorsMove(int powerLeft, int powerRight, int forwardTime)
{
  pros::Motor leftBaseMotor(1, pros::c::E_MOTOR_GEARSET_36, false);
  pros::Motor rightBaseMotor(2, pros::c::E_MOTOR_GEARSET_36, true);

  leftBaseMotor.move(powerLeft);
  rightBaseMotor.move(powerRight);
  delay(forwardTime);
  leftBaseMotor.move(0);
  rightBaseMotor.move(0);
}



void autonomous()
{

  baseMotorsMove(127, 127, 2000);
  delay(1000);
  baseMotorsMove(-127, -127, 2000);
  delay(1000);
  baseMotorsMove(127, -127, 1000);
  delay(1000);
  baseMotorsMove(-127, 127, 1000);
}
