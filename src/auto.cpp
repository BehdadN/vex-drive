#include "auto.h"

unsigned short int X_ERROR = 15;
// int Y_ERROR = 10;

void drive() {
  approach(Vision20, Vision20__DONUT);
}

void approach(vision v, signature sig) {
  while (true) {
    // TODO: largest object instead of objects[0]

    // vision: 316 pixels across, 212 down !!!
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);

    v.takeSnapshot(sig);

    // vision takes picture

    if (v.objects[0].exists) {

      int x_center = v.objects[0].centerX;

      // if the donut is there, print the x value of center
      // Brain.Screen.print(v.objects[0].centerX);

      Brain.Screen.print(v.objects[0].width);

      if (x_center < (158 - X_ERROR)) {
        while (x_center < (158 - X_ERROR)) {
          Drivetrain.turn(left);
          v.takeSnapshot(sig);
          x_center = v.objects[0].centerX;
        }
      }

      if (x_center > (158 + X_ERROR)) {
        while (x_center > (158 + X_ERROR)) {
          Drivetrain.turn(right);
          v.takeSnapshot(sig);
          x_center = v.objects[0].centerX;
        }
      }

      if (x_center < (158 - X_ERROR) && x_center > (158 + X_ERROR)) {

        while (x_center < (158 - X_ERROR) && x_center > (158 + X_ERROR)) {

          Brain.Screen.print("forward");
          Drivetrain.drive(forward);
        }
      }

    } else {
      Drivetrain.stop();
      Brain.Screen.print("nothing detected :(");
    }
    wait(1, seconds);
  }
}