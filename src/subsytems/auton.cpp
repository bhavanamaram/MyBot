#include "main.h"
#include <utility>
bool lockFlywheel=false;
int count=0;
void updateAuton(){
    flywheel.moveVoltage(12000); //start flywheel as the first task to allow maximum time to spin up 
    roller(); //do the roller
    driveForward(1.5);  //move foward
    turnToAngle(60);
    turnToAngle(60);
    turnToAngle(60);
    turnToAngle(60); //turn appx to the disc pile 

    pros::delay(10);

    driveForward(7);

    turnToAngle(-20);
     pros::delay(10);//wait 
    turnToAngle(-20);
    turnToAngle(-20); //turn towarsd the goal 
    pros::delay(10);//wait 
    driveForward(1);//drive foward towards the line
    while(flywheel.getActualVelocity()<400){ //wait until rpm hits 400
        pros::delay(1);   
        }
     index(); //index

    pros::delay(800); //wait 800 ms to allow a re-check
    while(flywheel.getActualVelocity()<430){ //wait till rpm hits 430 (higher becuase its the last disc)
        pros::delay(1);   
        }
     indexLast(); //index the last disc in the stack which takes more time 
    
    // turnToAngle(270);
    // pros::delay(10);
    // turnToAngle(270); //turn again to act as a second pid system 
    pros::delay(1000);
    // driveForward(1.5);  
    turnToAngle(-140));
    pros::delay(10);
    turnToAngle(-140);

    pros::delay(10);


    intakeMotor.moveVelocity(600);
    driveBlorward(-4.4, 0.5);

}