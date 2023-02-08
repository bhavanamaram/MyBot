#include "main.h"
#include <utility>
#include "autonFunctions.hpp"
bool lockFlywheel=false;
int count=0;
int route=7; 
// int target=0;
/*
route 1 is roller, move to middle, shoot, second rolelr (old) 
route 2 is move foward shoot roller                     (old)
route 3 is half of route one to move away from the alliance auton 
route 4 is for testing shooting/indexing
route 5 is new attempt of swp
route 6 is skills
*/
void driveToPoint(double posY, double posX,bool backward=false,double speed=1){
  double ogXPos=drive->getState().y.convert(okapi::foot); //get starting X position
  double ogYPos=drive->getState().x.convert(okapi::foot);//get starting Y position
  double distance = sqrt(pow((posX-ogXPos),2)+ pow((posY-ogYPos),2)); //calculate distance using distnace formula 
  double targetAngle = 0;

  if((posX-ogXPos)>=0 ){ //right
    targetAngle=((atan((posX-ogXPos)/(posY-ogYPos))*(180/3.14159)-90)*-1);  //invert and make it from 0 180
  }
  if(posX-ogXPos<0){ //left
    targetAngle=((atan((posX-ogXPos)/(posY-ogYPos))*(180/3.14159)+90)*-1); //invert and make it from 0 to -180 
  }
  if(backward==false){ //If driving shooter foward 
  turnToAngle(targetAngle);
  driveBlorward(distance,speed);
    }
  if(backward==true){ //If driving intake foward
    turnToAngle((-180+targetAngle));
    driveBackward(distance,speed);
  }
}
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
if(route==5){   

    roller();
     pros::delay(500);
    driveForward(0.6);
    pros::delay(200);
    turnToAngle(63.4);
    pros::delay(200);
    driveForward(4.4);
    //    flywheel.moveVelocity(440);
    turnToAngle(-35);
    driveForward(0.75);
    while(flywheel.getActualVelocity()<430){ //wait until rpm hits 430
            pros::delay(1);   
            }
        index(450); //index
        controller.rumble(".");
        //  flywheel.moveVelocity(410);
        pros::delay(900);
        while(flywheel.getActualVelocity()<450){ //wait till rpm hits 430 (higher becuase its the last disc)
            pros::delay(1);   
            }
        indexLast(430); //index the last disc in the stack which takes more time 
    // pros::delay(800);
    targetTBH=0;
    // driveBackward(-1,1);
    pros::delay(500);
    turnToAngle(-130);
    intakeMotor.moveVelocity(600);
    driveBackward(-4,0.5);
    
}
 if(route==6){
  roller();
  driveToPoint(0,1.8);
  driveToPoint(-1,0,true,0.75);
  turnToAngle(90); //turn into roller 
  leftDrive.moveVelocity(-25);
  rightDrive.moveVelocity(-25);
  pros::delay(500); //assist the bot into going into the roller 
  roller(); //do the roller acording to the function timings
  driveToPoint(-1,8);
   //shoot(); //commented because the function isnt made yet 
   driveToPoint(0.5,5,true,0.75);
   driveToPoint(2,7,true,0.75);
   driveToPoint(1,8);
  //shoot();
 }
 if(route==7){
    driveToPoint(0,2);
 }
 if(route==8){
    roller();
    driveToPoint(1,1);
    driveToPoint(1.8,1.8,true,0.75);
 }
} //update auton ends

