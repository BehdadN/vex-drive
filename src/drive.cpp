#include "vex.h"

bool intake = false;
bool grip = false;
bool liftup = false;
bool liftdown = false;

void grip_toggle() {
  if (grip) {
    claw.stop();
  } else {
    claw.spin(forward);
  }

  grip = !grip;
}

void intake_toggle() {
  if (intake) {
    hoover.stop();
  } else {
    hoover.spin(forward);
  }

  intake = !intake;
}

void lift_up() {
  if (liftup) {
    lift.stop();
  } else {
    lift.spin(forward);
  }

  liftup = !liftup;
}

void lift_down() {
  if (liftdown) {
    lift.stop();
  } else {
    lift.spin(reverse);
  }

  liftdown = !liftdown;
}

void arm_up() {
  arm.spin(forward);
}

void arm_down() {
  arm.spin(reverse);
}

void arm_stop() {
  arm.stop();
}

void drive_init() {
  Drivetrain.setDriveVelocity(60, percent);
  arm.setVelocity(20, percent);
  claw.setVelocity(50, percent);
  hoover.setVelocity(45, percent);
  lift.setVelocity(40, percent);
  lift.setStopping(hold);
  

  Controller1.ButtonUp.pressed(arm_up);
  Controller1.ButtonUp.released(arm_stop);
  Controller1.ButtonDown.pressed(arm_down);
  Controller1.ButtonDown.released(arm_stop);

  Controller1.ButtonY.pressed(grip_toggle);
  Controller1.ButtonA.pressed(intake_toggle);
  Controller1.ButtonX.pressed(lift_up);
  Controller1.ButtonB.pressed(lift_down);
}