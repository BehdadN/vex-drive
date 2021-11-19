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
// Controller1          controller                    
// Vision19             vision        19              
// Vision20             vision        20              
// BumperA              bumper        A               
// BumperB              bumper        B               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "angle_test.h"
#include "drive.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Brain.Screen.print("Brain Activated");
  atest();
}
