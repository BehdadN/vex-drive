#include "vex.h"
#include "drive.h"

void drive() {
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
        Brain.Screen.print(Vision20.objects[0].angle);
      } else {
        Brain.Screen.print("nothing detected :(");
      }
    } else {
      Brain.Screen.print("no mobile goal");
    }
    wait(1, seconds);
  }
}