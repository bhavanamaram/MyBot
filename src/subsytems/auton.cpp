#include "main.h"
#include <utility>
bool lockFlywheel=false;
int count=0;
int route=3;
/*
route 1 is roller, move to middle, shoot, second rolelr
route 2 is move foward shoot roller
route 3 is half of route one to move away from the alliance auton 
route 4 is for testing shit
*/
void updateAuton(){    
flywheel.moveVoltage(12000);  

if(route==1){
 
    roller();
    driveForward(0.6);
    pros::delay(200);
    turnToAngle(63.4);
    pros::delay(200);
    driveForward(4.4);
       flywheel.moveVelocity(440);
    turnToAngle(-23);
    driveForward(0.75);
    while(flywheel.getActualVelocity()<430){ //wait until rpm hits 400
            pros::delay(1);   
            }
        index(430); //index
        //  flywheel.moveVelocity(410);
        pros::delay(1200);
        while(flywheel.getActualVelocity()<430){ //wait till rpm hits 430 (higher becuase its the last disc)
            pros::delay(1);   
            }
        indexLast(430); //index the last disc in the stack which takes more time 
    pros::delay(800);
    flywheel.moveVelocity(0);
    turnToAngle(45);
    driveBlorward(7,0.7);
    controller.rumble("._.");
    turnToAngle(-90);
    // driveForward(-0.25);
    roller();
}
if(route==2){
    driveForward(2.4);
turnToAngle(35);
 while(flywheel.getActualVelocity()<420){ //wait until rpm hits 400
        pros::delay(1);   
        }
     index(420); //index
    while(flywheel.getActualVelocity()<430){ //wait till rpm hits 430 (higher becuase its the last disc)
        pros::delay(1);   
        }
     indexLast(430); //index the last disc in the stack which takes more time 
    pros::delay(800);
flywheel.moveVelocity(0);
turnToAngle(140);
driveBlorward( 2.8,0.7);
turnToAngle(0);
leftDrive.moveVelocity(-25);
rightDrive.moveVelocity(-25);
pros::delay(2000);
roller();
}
if(route==3){
 
    roller();
    driveForward(0.6);
    pros::delay(200);
    turnToAngle(63.4);
    pros::delay(200);
    driveForward(4.4);
       flywheel.moveVelocity(440);
    turnToAngle(-23);
    
    driveForward(0.75);
    while(flywheel.getActualVelocity()<430){ //wait until rpm hits 400
            pros::delay(1);   
            }
        index(430); //index
        //  flywheel.moveVelocity(410);
        pros::delay(1200);
        while(flywheel.getActualVelocity()<430){ //wait till rpm hits 430 (higher becuase its the last disc)
            pros::delay(1);   
            }
        indexLast(430); //index the last disc in the stack which takes more time 
    pros::delay(800);
    flywheel.moveVelocity(0);

}
if(route==4){
    flywheel.moveVoltage(12000);
     while(flywheel.getActualVelocity()<400){ //wait until rpm hits 400
        pros::delay(1);   
        }
    index(400);
}
}