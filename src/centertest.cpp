#include "centertest.h"
#include "vex.h"

void draw_center() {
  while(true) {
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);

    Vision20.takeSnapshot(Vision20__DONUT);

    if (Vision20.objects[0].exists) {

    Brain.Screen.drawCircle(Vision20.objects[0].centerX, Vision20.objects[0].centerY, 10);

    } else {
      Brain.Screen.print("nothing detected");
    }
  }
}