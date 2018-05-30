#include "main.hpp"

#include "../../Include/Driver/DriverVisionTracking.hpp"

#define BALL_SIG 1
#define BASE_P 1


Mutex calculateVisionMutex;


c::vision_object_s_t calculateVision()
{
  calculateVisionMutex.take(100);
  return mainVision.get_by_sig(0, BALL_SIG);
  calculateVisionMutex.give();
}



int driverBaseAngle()
{
  int baseP = BASE_P;


  int x_error = calculateVision().x_middle_coord;
  // Since 0,0 is the middle of the sensor's feild of veiw (set in initialize), any x deriviation is our error

  int finalBasePower = x_error * baseP;

  return finalBasePower;
}


int driverArmAngle()
{

  int y_error = calculateVision().y_middle_coord * -1; // Apperantly a positive y is down, I prefer to work with positive y being up

  int finalArmAngle = y_error; // Eventaully this will be the calculation for an absolute position

  return finalArmAngle;
}



void displayVision(void*)
{
  while(true) {
    calculateVision();
  }

}
