#include "auto.h"

using namespace vex;

unsigned short int X_ERROR = 15;
// int Y_ERROR = 10;

void test(vision vis, signature sig) {
  while (true) {
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    vis.takeSnapshot(sig);
    Brain.Screen.print(vis.objectCount);
    wait(1, seconds);
  }
}

void autonomous() {
  while (true) {
    // approach(false);
    approach(true);
  }
}

void approach(bool twenty) {
  if (twenty) {
    signature sig = Vision20__DONUT;
    // if vision20 is being used

    while (true) {
      // TODO: largest object instead of objects[0]

      // vision: 316 across, 212 down

      Brain.Screen.clearScreen();

      Vision20.takeSnapshot(sig);

      if (Vision20.objects[0].exists) {

        // TODO: new calculation using scaling
        Brain.Screen.print("hello");

        unsigned short int y_center = Vision20.objects[0].centerY;
        unsigned short int x_center = Vision20.objects[0].centerX;

        double leftbound = (0.5 * (316 * ((y_center + 70.67) / 353.3)));
        double x_range = (316 * (1 - ((y_center + 70.67) / 353.3)));
        double rightbound = leftbound + x_range;

        // TODO: draw center of object and the vision lines?
        Brain.Screen.drawLine(316, 0, 316, 212);
        Brain.Screen.drawLine(0, 212, 316, 212);

        Brain.Screen.drawLine(32, 0, 126, 212);
        Brain.Screen.drawLine(284, 0, 190, 212);

        Brain.Screen.drawCircle(x_center, y_center, 5);

        if (x_center < leftbound) {
          while (x_center < leftbound) {
            Drivetrain.turn(left);
            Vision20.takeSnapshot(sig);
            x_center = Vision20.objects[0].centerX;
          }
        } else if (x_center > rightbound) {
          while (x_center > rightbound) {
            Drivetrain.turn(right);
            Vision20.takeSnapshot(sig);
            x_center = Vision20.objects[0].centerX;
          }
        } else {
          Brain.Screen.print("forward");
          Drivetrain.drive(forward);
        }

      } else {
        Drivetrain.stop();
        Brain.Screen.print("nothing detected");
      }
    }
  }
}