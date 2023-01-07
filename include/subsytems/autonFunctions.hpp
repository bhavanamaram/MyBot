#include "main.h"
void roller();
void driveForward(double distance);
void index();
void indexLast(); //used to index the last disc which requires extra time
void turnToAngle(double targetAngle);
extern okapi::IMU  inertial;
extern double initAngle;
void driveBlorward(double distance, double scalar);