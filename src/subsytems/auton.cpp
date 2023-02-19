#include "main.h"
#include <utility>
#include "autonFunctions.hpp"
bool lockFlywheel=false;
int count=0;
int route=5; 
pros::ADIDigitalOut piSton ('H');
// int target=0;
/*
route 1 is swp
route 2 is left
route 3 is right 
route 4 is right ,but only roller
*/

void updateAuton(){    
// flywheel.moveVoltage(12000);  
targetTBH=0; //460
if(route==1){   //swp
       roller();
    driveForward(0.6); //drive foward to prevent clashing into the wal 
    turnToAngle(63.4); 
    driveForward(4.4);
    turnToAngle(-30);
    driveForward(0.75); 
    //shoot 2 (preloads)
     intakeMotor.moveVelocity(-600);
     pros::delay(2000); //200
      intakeMotor.moveVelocity(0);
      pros::delay(1000); //100
       intakeMotor.moveVelocity(-600);
     pros::delay(2000); //700
      intakeMotor.moveVelocity(0);
      //end of shoot block
    targetTBH=0;
    pros::delay(300);
    turnToAngle(-130);
    driveBackward(-6,0.75);  
    turnToAngle(-170);
    driveBackward(-1.5,1);
    turnToAngle(-90);
    leftDrive.moveVelocity(-600);
    rightDrive.moveVelocity(-600);
    pros::delay(100);
    leftDrive.moveVelocity(0);
rightDrive.moveVelocity(0);
roller();
driveForward(2); // expansion commented out
turnToAngle(-135);   
pros::delay(1000);
piSton.set_value(true);   
    
}
 if(route==2){ //left
    targetTBH=490;
    roller();
    driveForward(0.6);
     driveToPoint(1.4,1.4,false,0.9);
    pros::delay(1000);
    turnToAngle(-10);
     intakeMotor.moveVelocity(-600);
     pros::delay(200);
      intakeMotor.moveVelocity(0);
      pros::delay(1000);
       intakeMotor.moveVelocity(-600);
     pros::delay(2000);
      intakeMotor.moveVelocity(0);
      pros::delay(1000);
    intakeMotor.moveVelocity(600);
    driveToPoint(3.5,3.5,true,0.25);
    intakeMotor.moveVelocity(0);
    // shoot();
 }

 if(route==3){ //right         
 targetTBH=500;
 pros::delay(500);
    driveBackward(-2,1); //drive to roller
    turnToAngle(90); //turn into roller  leftDrive.moveVelocity(-600);
    // rightDrive.moveVelocity(-300);
    // leftDrive.moveVelocity(-300);
    // pros::delay(100);
    leftDrive.moveVelocity(0);
    rightDrive.moveVelocity(0);
    // driveToPoint(0,0.01,false,1);
    // driveToPoint(0.5,1.4,false,0.9);
    leftDrive.moveVelocity(-300);  
    rightDrive.moveVelocity(-300);
    pros::delay(300);
   //roler
// leftDrive.moveVelocity(-25);//set the drivetrain to move back at 25rpm
//     rightDrive.moveVelocity(-25);//we do 25 rpm to reduce the torque needed to do the roller.
//     pros::delay(700);
//     intakeMotor.moveVelocity(600); //move the roller at max speed
//     pros::delay(700); //wait half a second to allow roller to spin to our color 
//     leftDrive.moveVelocity(0);
//     rightDrive.moveVelocity(0);
//     intakeMotor.moveVelocity(0); //cut everyting besides flywheel
roller();
   //roller end
    pros::delay(50);
    driveForward(0.5);
    turnToAngle(99);
       while(flywheel.getActualVelocity()>450){ //allow 50 rpm diff
   intakeMotor.moveVelocity(-600);
   pros::delay(1);
}
intakeMotor.moveVelocity(0);
pros::delay(400);
intakeMotor.moveVelocity(-600);
pros::delay(1000);
intakeMotor.moveVelocity(0);
    turnToAngle(0);
    driveForward(0.5);
    // turnToAngle(45);
    turnToAngle(-135);
    intakeMotor.moveVelocity(600);
    driveBackward(-5,0.75);
    turnToAngle(135);
    //shoot
     intakeMotor.moveVelocity(-600);
     pros::delay(200);
      intakeMotor.moveVelocity(0);
      pros::delay(300);
       intakeMotor.moveVelocity(-600);
     pros::delay(700); 
     intakeMotor.moveVelocity(0);  
    
 }
 if(route==4){//right but only roller, not intaking
 targetTBH=500;
 pros::delay(2000);
    driveBackward(-2,1); //drive to roller
    turnToAngle(90); //turn into roller  leftDrive.moveVelocity(-600);
    rightDrive.moveVelocity(-300);
    leftDrive.moveVelocity(-300);
    pros::delay(100);
    leftDrive.moveVelocity(0);
    rightDrive.moveVelocity(0);
    // driveToPoint(0,0.01,false,1);
    // driveToPoint(0.5,1.4,false,0.9);
    leftDrive.moveVelocity(-25);  
    rightDrive.moveVelocity(-25);
    pros::delay(2000);
roller();
   //roller end
    pros::delay(50);
    driveForward(0.5);
    turnToAngle(98);
    pros::delay(1000);
      while(flywheel.getActualVelocity()>440){ //allow 50 rpm diff
   intakeMotor.moveVelocity(-600);
   pros::delay(1);
}
intakeMotor.moveVelocity(0);
      pros::delay(2000); 
    intakeMotor.moveVelocity(-600);
     pros::delay(3000); 
     intakeMotor.moveVelocity(0);
     targetTBH=0;
 }
 if(route==5){
    roller();
    driveForward(0.6); //drive foward to prevent clashing into the wal 
    turnToAngle(63.4); 
    driveForward(4.4);
    turnToAngle(-30);
    driveForward(0.75); 
    //shoot 2 (preloads)
     intakeMotor.moveVelocity(-600);
     pros::delay(2000); //200
      intakeMotor.moveVelocity(0);
      pros::delay(1000); //100
       intakeMotor.moveVelocity(-600);
     pros::delay(2000); //700
      intakeMotor.moveVelocity(0);
      //end of shoot block
    targetTBH=0;
 }
} //update auton ends

