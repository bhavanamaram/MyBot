#include "main.h"
#include "intake.hpp"
#include <utility>
void roller(){
    leftDrive.moveVelocity(-25);//set the drivetrain to move back at 25rpm
    rightDrive.moveVelocity(-25);//we do 25 rpm to reduce the torque needed to do the roller.
    intakeMotor.moveVelocity(300); //move the roller at max speed
    pros::delay(500); //wait half a second to allow roller to spin to our color 
    leftDrive.moveVelocity(0);
    rightDrive.moveVelocity(0);
    intakeMotor.moveVelocity(0); //cut everyting besides flywheel
}
void driveForward(double distance) {
    okapi::IterativePosPIDController drivePID = okapi::IterativeControllerFactory::posPID(0.75, 0.01, 0.01); //create a new drive object with specified pid

    const double target = distance; //idk why not just use distance

    drivePID.setTarget(target); //tels PROS: to move the drive using pid to distance

    double orgPosX = drive->getState().x.convert(okapi::foot); //store the orginal position
    double orgPosY = drive->getState().y.convert(okapi::foot);

    double distTravelled = 69696.420; //idk what this does but jad has it

    while (abs(target-distTravelled) >= 0.2) { //pid shit i think idk
        double dx = drive->getState().x.convert(okapi::foot) - orgPosX;
        double dy = drive->getState().y.convert(okapi::foot) - orgPosY;

        distTravelled = sqrt(dx*dx + dy*dy);
        
        double vel = drivePID.step(distTravelled);

        drive -> getModel() -> tank(vel, vel);

        pros::delay(10);
    }

    drivePID.reset(); //reset everything to move relitive 
    drive -> getModel() -> tank(0, 0); //stop the drive once target is met
}     
void index(){ //turn on indexer at max rpm for 10 ms 
intakeMotor.moveVelocity(-600);
pros::delay(10);
intakeMotor.moveVelocity(0);
}
void indexLast(){
    intakeMotor.moveVelocity(-600);
    pros::delay(500); //index for half a second due to this being the last disc in the stack
    intakeMotor.moveVelocity(0);
}