#include "main.hpp"


/*
How to use motor:
Here, define your different motors, controllers, ports, paramiters and options.
Then, make a prototype in the .hpp that gets put in all the other files, so they have access to the devices.
Put it in main.hpp
*/

pros::Controller mainController(CONTROLLER_MASTER);
pros::Motor leftBaseMotor(1, pros::c::E_MOTOR_GEARSET_36, false);
pros::Motor rightBaseMotor(5, pros::c::E_MOTOR_GEARSET_36, true);
pros::Motor hBaseMotor(2, pros::c::E_MOTOR_GEARSET_36, true);

pros::Motor armMotor(4);


pros::Vision mainVision(6);
