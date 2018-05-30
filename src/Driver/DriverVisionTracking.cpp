#include "main.hpp"

#include "../../Include/Driver/DriverVisionTracking.hpp"

#define BALL_SIG 1
#define BASE_P 1

c::vision_object_s_t visionOutput;



int driverBaseAngle()
{
  int baseP = BASE_P;

  visionOutput = mainVision.get_by_sig(0, BALL_SIG);

  int x_error = visionOutput.x_middle_coord; // Since 0,0 is the middle of the sensor's feild of veiw (set in initialize), any x deriviation is our error


  int finalBasePower = x_error * baseP;

  return finalBasePower;
}


int driverArmAngle()
{
  visionOutput = mainVision.get_by_sig(0, BALL_SIG);

  int y_error = visionOutput.y_middle_coord * -1; // Apperantly a positive y is down, I prefer to work with positive y being up

  int finalArmAngle = y_error; // Eventaully this will be the calculation for an absolute position

  return finalArmAngle;
}
