#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

#define PROS_USE_SIMPLE_NAMES // You can see the conversions in include\pros\misc.h line 70

/**
* If defined, C++ literals will be available for use.
* For instance, you can do `4_m = 50` to set motor 4's target velocity to 50
*/
#define PROS_USE_LITERALS

#include "api.hpp"

using namespace pros;
//using namespace okapi; // Not implemented yet
//#include "okapilib.h" // Not implemented yet
//#include "pros/api_legacy.h" // For old C functions

// User ________________________________________________________________________________________________________________________________

/*
Here, define your device prototypes, so the rest of the code can have access to them.
The actual definitions need to be in MotorDefinition.cpp
*/

#ifndef _MOTOR_CONFIG_
#define _MOTOR_CONFIG_
//extern pros::Controller mainController;
//extern pros::Motor leftBaseMotor;
//extern pros::Motor rightBaseMotor;
//extern pros::Motor hBaseMotor;
//extern pros::Motor armMotor;
extern pros::Vision mainVision;
#endif



/*
Include here prototypes and variables you want the entire project to have access to.
If not, include each header induvidually per source file.
How it works is, you prototype and declare functions from the source in the .hpp files.
Those are what the rest of the program use to interface with the actual source.
Then, in a source file, you can bring in all the different outside functions you want to use through the .hpp
*/








#endif  // _PROS_MAIN_H_
