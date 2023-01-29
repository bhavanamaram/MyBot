#include "main.h"
#include "flywheel.hpp" //vs code has errors here but it compiles find idk why.
/*
control scheme 
holding L2 spins flywheel to max speed 
tapping L2 toggles flywheel at 350 rpm
*/
bool toggle=false; //toggles the motor on and off
bool held=false;
bool lock=false;//prevents the toggle spam (stuttering of the motor which is damaging)
bool reverse=false;
bool toggleRumble=true;
double targetTBH=360; //define
double error=0; //define
double output=0;
double tbh=0;
double prev_error=0;
bool initiaized=false;
double k=0;
double v=0;

int Time = pros::millis();
Motor flywheel(10,true,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
static pros::Task my_task (TBH, NULL, TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT, "Example Task");

void updateFlywheel(){

 if(controller.getDigital(ControllerDigital::L2) == 1){
    held=true;
    
    //using voltage instead of velocity to ignore pid and spin as fast as possible 
    if(!lock){ //lock is inverted to make more logical sense (easier to debug)
        toggle=!toggle; //swaps toggle 
    }
    lock=true;
 }
    if(controller.getDigital(ControllerDigital::L2) == 0){ //if the button is not being held, reset the lock to allow toggle to be changed
        lock=false;
        held=false;
    }

    //controll the flywheel based on toggling system above 
    if(flywheel.getActualVelocity()>350 && toggleRumble==true){
        controller.rumble(".");
        toggleRumble = false;
    }
    if(held){
        flywheel.moveVoltage(12000);//if button is held it goes to max rpm
        leftDrive.setBrakeMode(AbstractMotor::brakeMode::hold);
        rightDrive.setBrakeMode(AbstractMotor::brakeMode::hold);
    }
    else if(toggle && held==false){
        // flywheel.moveVelocity(360);
        targetTBH=360;
         //move the flywheel at 350 rpm if toggled 
         leftDrive.setBrakeMode(AbstractMotor::brakeMode::hold);
         rightDrive.setBrakeMode(AbstractMotor::brakeMode::hold); //set to hold to prevent moving while shooting 
    }
    
    else if(!toggle && held==false && !reverse){
        flywheel.moveVelocity(0); //stop the flywheel if toggle is off
        targetTBH=0;
        // moveFlywheel.remove;
        if(flywheel.getActualVelocity()<300){
            toggleRumble=true;
        }
        if(state==1){
            leftDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
            rightDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
        }
    }
    if(controller.getDigital(ControllerDigital::L1) == 1 && !toggle && !held){
        // flywheel.moveVoltage(-12000);
        reverse=true;
    }
    if (controller.getDigital(ControllerDigital::L1)==0 && !held &&!toggle){
        flywheel.moveVelocity(0);
        targetTBH=0;
        reverse=false;
    }
    
   
    
 } //updateFlywheel Ends








/*

error = goal - currentSpeed;                // calculate the error;
output += gain * error;                     // integrate the output;
if (signbit(error)!= signbit(prev_error)) { // if zero crossing,
  output = 0.5 * (output + tbh);            // then Take Back Half
  tbh = output;                             // update Take Back Half variable
  prev_error = error;                       // and save the previous error
}

*/
   
// void TBH(void*){
//   while(true){
//       Time = pros::millis();
//     pros::delay(10);
//    error= targetTBH-flywheel.getActualVelocity();
//    if(targetTBH!=0){
// output=abs(pow(((targetTBH/(1+pow((2.718),-0.003*error)))*20),1.02)+3352);
//    }
//    if(targetTBH==0){
//     output=0;
//    }
// if(output>12000){
//     flywheel.moveVoltage(12000);
// }else{
//     flywheel.moveVoltage(output);
// }
//    flywheel.moveVelocity((pow(targetTBH/(1+pow((2.718),-0.01*error)),1)));
//   flywheel.moveVelocity(targetTBH);
// //  printf("Voltage %d )\n", flywheel.getVoltage());
// //  pros::delay(500);
//   }

//   }
// }
void TBH(void* ){
    //flexwheel mass is 117.934grams 

while(true){
    v=targetTBH*19+422;
   pros::delay(10);
   double k=1.2/(2*targetTBH);
   error=targetTBH-flywheel.getActualVelocity();
   output=(((targetTBH/1+pow((2.718),(-k*error)))*20)+(v));
}
}

       