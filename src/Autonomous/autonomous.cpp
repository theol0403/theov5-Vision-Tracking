#include "main.hpp"

//#include "DriverBaseControl.hpp"
// comp. control has not been fully implemented yet, so
// this function will never be called

void baseMotorsMove(int degreesLeft, int degreesRight)
{
  pros::Motor leftBaseMotor(1, pros::c::E_MOTOR_GEARSET_36, false);
  pros::Motor rightBaseMotor(2, pros::c::E_MOTOR_GEARSET_36, true);

  int leftLastPos = leftBaseMotor.get_position();
  int rightLastPos = rightBaseMotor.get_position();
  int leftError;
  int rightError;
  float driveKp = 0.1;
  while (true)
  {
    leftError = leftBaseMotor.get_position() - degreesLeft - leftLastPos;
    rightError = rightBaseMotor.get_position() - degreesRight - rightLastPos;

    leftBaseMotor.move(leftError * driveKp);
    rightBaseMotor.move(rightError * driveKp);
  }
}



void autonomous()
{

  baseMotorsMove(700, 700);
  delay(4000);
  baseMotorsMove(700, 700);

}
