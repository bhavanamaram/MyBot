#include "main.h"
// #include "drive.hpp"  
#include "okapi/api/odometry/point.hpp"
using namespace okapi;
Motor rightFront(18, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);// motor for the front(drive)
Motor rightTop(1, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);// the right motor on he top, back (drive)
Motor rightBottom(2, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);// right motor on the bottom,back (drive)

Motor leftFront(6, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);//motor for the front (drive)
Motor leftTop(4, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);//the right motor on he top, back (drive)
Motor leftBottom(5, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);// left motor on the bottom,back (drive)

MotorGroup leftDrive ({leftFront,leftTop,leftBottom}); //define the left side of the drive as a motor group to allow cleaner code
MotorGroup rightDrive({rightFront,rightTop,rightBottom});//define the left side of the drive as a motor group to allow cleaner code
//imu 7
// MotorGroup left(leftFront,leftTop,leftBottom);
  std::shared_ptr<OdomChassisController> drive =ChassisControllerBuilder()
    .withMotors({leftFront, leftTop, leftBottom}, {rightFront, rightTop, rightBottom}) //defines the left and right side of the drive
    .withDimensions(  AbstractMotor::gearset::blue, {{4_in, 15_in}, okapi::imev5BlueTPR})
    .withGains(//pid
        {0.0015, 0,  0.000085}, // distance controller gains
        {0.001, 0,0}, // turn controller gains
        {0.001, 0, 0}  // angle controller gains (helps drive straight)
    )
    .withOdometry({{4_in, 15_in}, quadEncoderTPR}) //specifies the tracking wheels dimentions
    .buildOdometry();
    //this creates a drive as an object with PID and the default odometry functions, most of the default odom functions suck tho so we make our own in odom files


  void updateDrive(){
      pros::lcd::set_text(1, std::to_string(drive->getState().x.convert(okapi::foot))); //displays the X coordinate on the LCD of the screen per tick
      pros::lcd::set_text(2, std::to_string(drive->getState().y.convert(okapi::foot))); //displays the X coordinate on the LCD of the screen per tick

    // drive -> getModel() -> tank(-translate1.power, -translate1.power);
    
    drive -> getModel() -> arcade(controller.getAnalog(ControllerAnalog::leftY), -controller.getAnalog((ControllerAnalog::leftX)));
    if (controller.getDigital(ControllerDigital::X) == 1){
      leftDrive.setBrakeMode(AbstractMotor::brakeMode::hold);
      rightDrive.setBrakeMode(AbstractMotor::brakeMode::hold);
    }
    else if (controller.getDigital(ControllerDigital::Y) == 1){
      leftDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
      rightDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
    }
 
  }
