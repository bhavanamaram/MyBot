#include "main.h"
#include "flywheel.hpp" //vs code has errors here but it compiles find idk why.
/*
control scheme 
holding L2 spins flywheel to max speed 
tapping L2 toggles flywheel at 350 rpm
*/
bool toggle=false; //toggles the motor on and off
bool lock=false;//prevents the toggle spam (sputtering of the motor which is damaging)
Motor flywheel(10,true,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
void updateFlywheel(){
 if(controller.getDigital(ControllerDigital::L2) == 1){
    flywheel.moveVoltage(1200);//if button is held it goes to max rpm
    //using voltage instead of velocity to ignore pid and spin as fast as possible 
    if(!lock){ //lock is inverted to make more logical sense (easier to debug)
        toggle=!toggle; //swaps toggle 
    }
    lock=true;
 }
    if(controller.getDigital(ControllerDigital::L2) == 0){ //if the button is not being held, reset the lock to allow toggle to be changed
        lock=false;
    }

    //controll the flywheel based on toggling system above 
    if(toggle){
        flywheel.moveVelocity(360); //move the flywheel at 350 rpm if toggled 
    }
    if(!toggle){
        flywheel.moveVelocity(0); //stop the flywheel if toggle is off
    }
 } //updateFlywheel Ends

   

       