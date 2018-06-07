#include "main.hpp"
#include "DriverArmP.hpp"
#include "DriverVisionTracking.hpp"

#define potRange 3036 //The pot value of the range of the arm
#define potAngle 270 //The angle value of the range of the arm
#define potOffset 0 //The offset for a certain pot value to be zero degrees

#define ARM_P 1.3

void armP(void*)
{
  Motor armMotor(3);

  float error;
  //int wanted;
  float finalArmPower;

  while(true)
  {
    //wanted = (potRange / potAngle * driverArmAngle()) + potOffset;
    // error = wanted - pot;

    error = driverArmAngle();

    finalArmPower = error * ARM_P;


    if (mainController.get_digital(E_CONTROLLER_DIGITAL_LEFT))
    {
      armMotor.move_voltage(finalArmPower * 100);
    }
    else
    {
      armMotor.move_voltage(0);
    }

    delay(10);
  }
}
