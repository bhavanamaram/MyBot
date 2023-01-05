#include "main.h"
bool lockFlywheel=false;
int count=0;
void updateAuton(){
    flywheel.moveVelocity(600); //start flywheel as the first task to allow maximum time to spin up 
    roller(); //do the roller
    driveForward(1.5);  //move foward
    drive->turnToAngle( 60.43*okapi::degree);
    driveForward(2);
    
}