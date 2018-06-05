#include "main.hpp"

#include "DriverVisionTracking.hpp"

#define BALL_SIG 2 // Defines the vision signature that is trained for the ball
#define BASE_P 0.7 // The Kp for X error / base power
#define VISION_WIDTH 500
#define VISION_HEIGHT 400

float driverBaseAngle() //Function that outputs the power to be sent to the base for turning
{
  int x_error = calculateVision().x_middle_coord - VISION_WIDTH/2;
  // Centers the vision, and any x deriviation is our error
  // If the vision sensor is not centered with the arm, a trig formula needs to be here.
  // It will then output absolute, or most likely relative angle error. P will have to be changed

  float finalBasePower = x_error * BASE_P; // For now a simple P based on X deriviation from the center of the vision

  return finalBasePower; //Returns power to be sent to the base
}


int driverArmAngle()
{

  int y_error = (calculateVision().y_middle_coord * -1) + VISION_HEIGHT - VISION_HEIGHT/2;
  // Appearently a positive y is down, I prefer to work with positive y being up
  // Centers the vision, and any x deriviation is our error
  // If the vision sensor is not centered with the arm, a trig formula needs to be here.
  // It will then output absolute angle error, to be P'd by the arm task

  int finalArmAngle = y_error; // Eventaully this will be the calculation for an absolute position, but for now it's P

  return finalArmAngle; // Returns final angle the arm needs to be at (currently y error)
}

//
c::vision_object_s_t visionScannerData;
bool updateVision;

c::vision_object_s_t calculateVision() //Function to read vision sensor data
{
  updateVision = true;
  return visionScannerData;
}


void monitorVisionTask(void*)
{
  while(true)
  {
    pros::Vision mainVision(6);
    if(updateVision)
    {
      visionScannerData = mainVision.get_by_sig(0, BALL_SIG); // Returns info for largest object of the signature
      updateVision = false;
    }
    delay(100);
  }
}
