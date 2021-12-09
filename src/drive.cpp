#include "vex.h"

bool intake = false;

void intake_toggle() {
  if (intake) {
    Motor1.stop();
    intake = false;
  } else {
    Motor1.setVelocity(60, percent);
    Motor1.spin(forward);
    intake = true;
  }
}