#include "main.h"
#include <utility>
bool lockFlywheel=false;
int count=0;
int route=1;
void updateAuton(){    
flywheel.moveVoltage(12000);    
if(route==1){
roller();
driveForward(0.6);
pros::delay(200);
turnToAngle(63.4);
pros::delay(200);
driveForward(4.4);
turnToAngle(-27);
driveForward(0.25);
 while(flywheel.getActualVelocity()<360){ //wait until rpm hits 400
        pros::delay(1);   
        }
     index(); //index
    //  flywheel.moveVelocity(410);
     pros::delay(1200);
    while(flywheel.getActualVelocity()<400){ //wait till rpm hits 430 (higher becuase its the last disc)
        pros::delay(1);   
        }
     indexLast(); //index the last disc in the stack which takes more time 
pros::delay(800);
flywheel.moveVelocity(0);   
turnToAngle(45);
controller.rumble("._.");
driveBlorward(7.3,0.7);
turnToAngle(-90);
// driveForward(-0.25);
roller();
}
if(route==2){
    driveForward(2.6);
turnToAngle(91);
 while(flywheel.getActualVelocity()<400){ //wait until rpm hits 400
        pros::delay(1);   
        }
     index(); //index
    while(flywheel.getActualVelocity()<430){ //wait till rpm hits 430 (higher becuase its the last disc)
        pros::delay(1);   
        }
     indexLast(); //index the last disc in the stack which takes more time 
    pros::delay(800);
    turnToAngle(45);
    controller.rumble("._.");
pros::delay(300);
turnToAngle(-47);
driveForward(-2);
turnToAngle(0);
driveForward(-0.5);
roller();
}
if(route==3){
roller();
driveForward(0.6);
pros::delay(200);
turnToAngle(63.4);
pros::delay(200);
driveForward(4.4);
turnToAngle(-27);
driveForward(0.25);
 while(flywheel.getActualVelocity()<360){ //wait until rpm hits 400
        pros::delay(1);   
        }
     index(); //index
    //  flywheel.moveVelocity(410);
     pros::delay(1200);
    while(flywheel.getActualVelocity()<400){ //wait till rpm hits 430 (higher becuase its the last disc)
        pros::delay(1);   
        }
     indexLast(); //index the last disc in the stack which takes more time 
pros::delay(800);
flywheel.moveVelocity(0);  
}
}