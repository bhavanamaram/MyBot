#include "main.h"
using namespace okapi;
bool ToggleBlooper=false;
bool LockBlopper=true;
pros::ADIDigitalOut blooperPiston ('C');

void updateBlooper(){
    if(controller.getDigital(ControllerDigital::left) == 1){  
          if(LockBlooper){
          ToggleBlooper=!ToggleBlooper;
          LockBlooper=false;
          piston.set_value(ToggleBlooper);    
        }
    }
        if(controller.getDigital(ControllerDigital::left) == 0){
          LockBlooper=true;
        }

}
