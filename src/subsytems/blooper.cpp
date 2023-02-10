#include "main.h"
using namespace okapi;
bool ToggleBlooper=false;
bool LockBlooper=true;
pros::ADIDigitalOut blooperPiston ('C');

void updateBlooper(){
    if(controller.getDigital(ControllerDigital::down) == 1){  
          if(LockBlooper){
          ToggleBlooper=!ToggleBlooper;
          LockBlooper=false;
          blooperPiston.set_value(ToggleBlooper);    
        }
    }
        if(controller.getDigital(ControllerDigital::down) == 0){
          LockBlooper=true;
        }

}
