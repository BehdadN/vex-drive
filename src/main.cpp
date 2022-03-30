/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       behdad                                                    */
/*    Created:      Thu Nov 11 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    9, 10           
// Vision19             vision        19              
// Vision20             vision        20              
// claw                 motor         3               
// hoover               motor         4               
// Controller1          controller                    
// lift                 motor_group   5, 6            
// arm                  motor_group   1, 2            
// Controller2          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

// #include "auto.h"
#include "drive.h"
#include "test.h"
#include "vex.h"

using namespace vex;

// divide all angles by 1.5!!!

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // Controller1.ButtonA.pressed(intake_toggle);

  Brain.Screen.print("Brain Activated"); // don't remove this line!!

  drive_init();
}
