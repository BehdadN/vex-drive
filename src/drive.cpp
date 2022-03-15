#include "vex.h"

bool intake = false;
bool grip = false;
bool liftup = false;
bool liftdown = false;
bool liftexact = false;

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

void lift_exact() {
  // trial and error
  int angle = 191;
  if (liftexact) {
    lift.spinFor(reverse, angle, degrees);
  } else {
    lift.spinFor(forward, angle, degrees);
  }

  liftexact = !liftexact;
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
  claw.setVelocity(50, percent);
  claw.setMaxTorque(100, percent);
  hoover.setVelocity(30, percent);
  hoover.setMaxTorque(100, percent);
  lift.setVelocity(40, percent);
  lift.setStopping(hold);
  lift.setPosition(0, degrees);
  lift.setMaxTorque(100, percent);
  arm.setVelocity(40, percent);
  arm.setStopping(hold);
  arm.setPosition(0, degrees);
  arm.setMaxTorque(100, percent);

  arm.spinFor(forward, 180, degrees);
  arm.stop();
  

  Controller1.ButtonUp.pressed(arm_up);
  Controller1.ButtonUp.released(arm_stop);
  Controller1.ButtonDown.pressed(arm_down);
  Controller1.ButtonDown.released(arm_stop);

  Controller1.ButtonY.pressed(grip_toggle);
  Controller1.ButtonA.pressed(intake_toggle);
  // Controller1.ButtonX.pressed(lift_up);
  // Controller1.ButtonB.pressed(lift_down);
  Controller1.ButtonB.pressed(lift_exact);
}