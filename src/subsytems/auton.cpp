#include "main.h"
#include "autonFunctions.hpp"

void updateAuton(){
    flywheel.moveVelocity(460); //start flywheel as the first task to allow maximum time to spin up 
    roller(); //do the roller
    driveForward(1.5);  //move foward
    for(int i=0; flywheel.getActualVelocity()>=450;i++){
        //wait until flywheel velocity is greator than 450
    }
    index();
     for(int i=0; flywheel.getActualVelocity()>=450;i++){
        //wait until flywheel velocity is greator than 450
    }
    indexLast();
}