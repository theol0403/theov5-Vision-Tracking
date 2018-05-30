#include "main.hpp"


void initialize()
{
    mainVision.set_zero_point(pros::c::E_VISION_ZERO_CENTER);
}

// the following functions don't work presently because comp. control
// hasn't been fully implemented
void disabled() {}
void competition_initialize() {}
