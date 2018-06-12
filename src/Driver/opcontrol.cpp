#include "main.hpp"
#include "DriverBaseControl.hpp"





void opcontrol() {

Task driverBaseTask(driverBaseControl, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "DriverBaseControl");
  while (true)
  {
    delay(100);


  }
}
