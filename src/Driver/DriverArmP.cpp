#include "main.hpp"
#include "../../Include/Driver/DriverArmP.hpp"
#include "../../Include/Driver/DriverVisionTracking.hpp"

#define potRange 3036 //The pot value of the range of the arm
#define potAngle 270 //The angle value of the range of the arm
#define potOffsetToZero 0 //The offset for a certain pot value to be zero degrees

#define ARM_P 0.1

void armP(void*)
{
  int error;
  //int wanted;
  int finalArmPower;

  while(true)
  {
    //wanted = (potRange / 360 * driverArmAngle()) + zeroOffset;
    // error = wanted - pot;

    error = driverArmAngle();

    finalArmPower = error * ARM_P;

    armMotor.move(finalArmPower);
    delay(20);
  }
}
