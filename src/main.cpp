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
// Drivetrain           drivetrain    1, 2            
// Controller1          controller                    
// Vision19             vision        19              
// Vision20             vision        20              
// BumperA              bumper        A               
// BumperB              bumper        B               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  while (true) {
    // vision: 316 pixels across, 212 down !!!
    
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);

    Vision20.takeSnapshot(Vision20__DONUT);

    if (Vision20.objectCount != 0) {
      Brain.Screen.print(Vision20.objects[0].centerX);
    } else {
      Brain.Screen.print("nothing detected :(");
    }

    wait(1, seconds);
  }
  
  
}
