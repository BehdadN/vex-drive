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

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  while (true) {
    // vision: 316 pixels across, 212 down !!!
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);

    if (BumperA.pressing() && BumperB.pressing()) {
      // if we are holding mobile goal
      

      Vision20.takeSnapshot(Vision20__DONUT);

      // vision20 takes picture

      if (Vision20.objects[0].exists) {
        // if the donut is there, print the x value of center
        Brain.Screen.print(Vision20.objects[0].centerX);
      } else {
        Brain.Screen.print("nothing detected :(");
      }
    } else {
      Brain.Screen.print("no mobile goal");
    }
    wait(1, seconds);
  }
}
