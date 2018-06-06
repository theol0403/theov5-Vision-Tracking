#include "main.hpp"
#include "DriverArmP.hpp"
#include "DriverVisionTracking.hpp"

#define potRange 3036 //The pot value of the range of the arm
#define potAngle 270 //The angle value of the range of the arm
#define potOffset 0 //The offset for a certain pot value to be zero degrees

#define ARM_P 0.1

void armP(void*)
{
  pros::ADIMotor armMotor(1);

  int error;
  //int wanted;
  int finalArmPower;

  while(true)
  {
    //wanted = (potRange / potAngle * driverArmAngle()) + potOffset;
    // error = wanted - pot;

    error = driverArmAngle();

    finalArmPower = error * ARM_P;

    armMotor.set_value(finalArmPower);
    delay(20);
  }
}