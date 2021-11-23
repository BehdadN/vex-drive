#include "vex.h"
#include "auto.h"

int X_ERROR = 15;
int Y_ERROR = 10;

void drive() {
  while (true) {
    // vision: 316 pixels across, 212 down !!!
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);

    // if (BumperA.pressing() && BumperB.pressing()) {
      // if we are holding mobile goal
      

      Vision20.takeSnapshot(Vision20__DONUT);

      // vision20 takes picture

      if (Vision20.objects[0].exists) {

        int x_center = Vision20.objects[0].centerX;
        
        // if the donut is there, print the x value of center
        // Brain.Screen.print(Vision20.objects[0].centerX);

        Brain.Screen.print(Vision20.objects[0].width);

        if (x_center < (158 - X_ERROR)) {
          while (Vision20.objects[0].centerX < (158 - X_ERROR)) {
            Drivetrain.turn(left);
            Vision20.takeSnapshot(Vision20__DONUT);
            x_center = Vision20.objects[0].centerX;
          }
        }

        if (x_center < (158 + X_ERROR)) {
          while (x_center < (158 + X_ERROR)) {
            Drivetrain.turn(right);
            Vision20.takeSnapshot(Vision20__DONUT);
            x_center = Vision20.objects[0].centerX;
          }
        }

        if (x_center < (158 - X_ERROR) && x_center > (158 + X_ERROR)) {
          Drivetrain.drive(forward);
          
        }

        // if (Vision20.objects[0].centerX < )
      } else {
        Drivetrain.stop();
        Brain.Screen.print("nothing detected :(");
      }
    // } else {
    //   Brain.Screen.print("no mobile goal");
    // }
    wait(1, seconds);
  }
}