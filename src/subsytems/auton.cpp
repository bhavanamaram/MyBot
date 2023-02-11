#include "main.h"
#include <utility>
#include "autonFunctions.hpp"
bool lockFlywheel=false;
int count=0;
int route=5; 
// int target=0;
/*
route 1 is roller, move to middle, shoot, second rolelr (old) 
route 2 is move foward shoot roller                     (old)
route 3 is half of route one to move away from the alliance auton 
route 4 is for testing shooting/indexing
route 5 is new attempt of swp
route 6 is skills
route 7 is left roller  
route 8 is testing
*/

void updateAuton(){    
// flywheel.moveVoltage(12000);  
targetTBH=460;
if(route==1){
 
    roller();
     pros::delay(500);
    driveForward(0.6);
    pros::delay(200);
    turnToAngle(63.4);
    pros::delay(200);
    driveForward(4.4);
    //    flywheel.moveVelocity(440);
    turnToAngle(-23);
    driveForward(0.75);
    while(flywheel.getActualVelocity()<410){ //wait until rpm hits 430
            pros::delay(1);   
            }
        index(430); //index
        controller.rumble(".");
        //  flywheel.moveVelocity(410);
        pros::delay(900);
        while(flywheel.getActualVelocity()<420){ //wait till rpm hits 430 (higher becuase its the last disc)
            pros::delay(1);   
            }
        indexLast(420); //index the last disc in the stack which takes more time 
    // pros::delay(800);
    flywheel.moveVelocity(0);
    turnToAngle(50);
    driveForward(7);
    
    turnToAngle(-170);
    // driveForward(0.3);
    turnToAngle(-90);
    // driveForward(-0.25);   
    leftDrive.moveVelocity(-25);
    rightDrive.moveVelocity(-25);
    pros::delay(300);
    roller();
}

if(route==2){
    //  flywheel.moveVoltage(8800);
    // flywheel.moveVelocity(420);
    // pros::delay(5000);
    driveForward(2.4);
// turnToAngle(29);
//   while(flywheel.getActualVelocity()<430){ //wait until rpm hits 400
//             pros::delay(1);   
//             }
//         index(420); //index
//         //  flywheel.moveVelocity(410);
//         pros::delay(700);
// while(flywheel.getActualVelocity()<440){ //wait till rpm hits 430 (higher becuase its the last disc)
//     pros::delay(1);   
//         }
        // indexLast(430); //index the last disc in the stack which takes more time 
    // intakeMotor.moveVelocity(-600);
    controller.rumble(".");
    pros::delay(600);
    intakeMotor.moveVelocity(0);
// pros::delay(800);
flywheel.moveVelocity(0);
pros::delay(200);
turnToAngle(140);
driveBlorward( 2.8,0.7);
turnToAngle(0);
leftDrive.moveVelocity(-25);
rightDrive.moveVelocity(-25);
pros::delay(1000);
leftDrive.moveVelocity(-25);//set the drivetrain to move back at 25rpm
    rightDrive.moveVelocity(-25);//we do 25 rpm to reduce the torque needed to do the roller.
     //move the roller at max speed
    pros::delay(1000); //wait half a second to allow roller to spin to our color 
    leftDrive.moveVelocity(-3);
    rightDrive.moveVelocity(-3);
    intakeMotor.moveVelocity(300);
    pros::delay(600);
    intakeMotor.moveVelocity(0);
}
if(route==3){
    // flywheel.moveVoltage(10000);
    roller();
    pros::delay(500);
    driveForward(0.6);
    // pros::delay(200);
    turnToAngle(63.4);
    pros::delay(100);
    driveForward(4.4);
       
    turnToAngle(-32);
    
    driveForward(0.75);
    static double targetF = 430;
// pros::Task moveFlywheel(bangBang);
    while(flywheel.getActualVelocity()<430){ //wait until rpm hits 400
            pros::delay(1);   
            }
        index(430); //index
        //  flywheel.moveVelocity(410);
        pros::delay(700);
        while(flywheel.getActualVelocity()<440){ //wait till rpm hits 430 (higher becuase its the last disc)
            pros::delay(1);   
            }
        indexLast(440); //index the last disc in the stack which takes more time 
    pros::delay(800);
    flywheel.moveVelocity(0);
    // moveFlywheel.remove();
    //route 3 ends

}
if(route==4){
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
if(route==5){   //swp

    roller();
     pros::delay(10);
    driveForward(0.6);
    // pros::delay(200);
    turnToAngle(63.4);
    // pros::delay(200);
    driveForward(4.4);
    //    flywheel.moveVelocity(440);
    turnToAngle(-30);
    driveForward(0.75);
    // while(flywheel.getActualVelocity()<430){ //wait until rpm hits 430
    //         pros::delay(1);   
    //         }
    //     index(450); //index
    //     controller.rumble(".");
    //     //  flywheel.moveVelocity(410);
    //     pros::delay(900);
    //     while(flywheel.getActualVelocity()<450){ //wait till rpm hits 430 (higher becuase its the last disc)
    //         pros::delay(1);   
    //         }
    //     indexLast(430); //index the last disc in the stack which takes more time 
    // pros::delay(800);
     intakeMotor.moveVelocity(-600);
     pros::delay(200);
      intakeMotor.moveVelocity(0);
      pros::delay(1000);
       intakeMotor.moveVelocity(-600);
     pros::delay(700);
      intakeMotor.moveVelocity(0);
    targetTBH=0;
    // driveBackward(-1,1);
    pros::delay(300);
    turnToAngle(-135);
    intakeMotor.moveVelocity(600);
    driveBackward(-6,0.75);  
    turnToAngle(-170);
    driveBackward(-1.5,1);
    // driveToPoint(6,9,false,1);
    turnToAngle(-90);
    leftDrive.moveVelocity(-300);
    rightDrive.moveVelocity(-300);
    pros::delay(100);
    leftDrive.moveVelocity(0);
rightDrive.moveVelocity(0);
roller();
    
    
}
 if(route==6){//skills
 roller();
    // driveToPoint(0,0.01,false,1);
    // driveToPoint(0.5,1.4,false,0.9);
    leftDrive.moveVelocity(100);
    rightDrive.moveVelocity(100);
    pros::delay(500);
     leftDrive.moveVelocity(0);
    rightDrive.moveVelocity(0);
     driveToPoint(0,1.4,false,1);
     turnToAngle(90);
    leftDrive.moveVelocity(-300);
    rightDrive.moveVelocity(-300);
    pros::delay(1000);
       leftDrive.moveVelocity(-25);
    rightDrive.moveVelocity(-25);
    roller();
    // driveToPoint(7,10,false,1);
 }
 if(route==7){ //left
    targetTBH=490;
    roller();
    // driveToPoint(0,0.01,false,1);
    // driveToPoint(0.5,1.4,false,0.9);
    leftDrive.moveVelocity(25);
    rightDrive.moveVelocity(25);
    pros::delay(50);
     leftDrive.moveVelocity(0);
    rightDrive.moveVelocity(0);
     driveToPoint(1.4,1.4,false,0.9);
    pros::delay(1000);
    turnToAngle(-10);
    // shoot();
     intakeMotor.moveVelocity(-600);
     pros::delay(200);
      intakeMotor.moveVelocity(0);
      pros::delay(1000);
       intakeMotor.moveVelocity(-600);
     pros::delay(1000);
      intakeMotor.moveVelocity(0);
      pros::delay(1000);
    intakeMotor.moveVelocity(600);
    // driveToPoint(3.0,3.0,true,1);
    driveToPoint(3.5,3.5,true,0.25);
    intakeMotor.moveVelocity(0);
    // shoot();
 }
 if (route==8){ //testing
driveToPoint(2,2,false,1);
pros::delay(1000);
driveToPoint(3,3,true,1);
pros::delay(1000);
// driveToPoint(3,3,false,1);
// turnToAngle(-90);
driveToPoint(1,3,true,1);
 }
 if(route==9){
    driveBackward(-2,1);
    turnToAngle(90);
    // driveToPoint(0,0.01,false,1);
    // driveToPoint(0.5,1.4,false,0.9);
    leftDrive.moveVelocity(-100);
    rightDrive.moveVelocity(-100);
    pros::delay(500);
     leftDrive.moveVelocity(-25);
    rightDrive.moveVelocity(-25);
    pros::delay(500);
    roller();
    pros::delay(50);
    driveForward(2);
    turnToAngle(45);
    driveForward(6);
    
    
 }
} //update auton ends

