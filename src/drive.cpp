#include "vex.h"

bool intake = false;
bool grip = false;
bool liftup = false;
bool liftdown = false;
bool liftexact = false;

void grip_toggle() {
  // Brain.Screen.clearScreen();
  // Brain.Screen.setCursor(1, 1);
  // Brain.Screen.print("claw");
  if (grip) {
    claw.stop();
  } else {
    claw.spin(reverse);
  }

  grip = !grip;
}

void intake_toggle() {
  // Brain.Screen.clearScreen();
  // Brain.Screen.setCursor(1, 1);
  // Brain.Screen.print("intake");
  if (intake) {
    hoover.stop();
  } else {
    hoover.spin(forward);
  }

  intake = !intake;
}

void lift_up() {
  // Brain.Screen.clearScreen();
  // Brain.Screen.setCursor(1, 1);
  // Brain.Screen.print("lift up");
  if (liftup) {
    lift.stop();
  } else {
    lift.spin(forward);
  }

  liftup = !liftup;
}

void lift_down() {
  // Brain.Screen.clearScreen();
  // Brain.Screen.setCursor(1, 1);
  // Brain.Screen.print("lift down");
  if (liftdown) {
    lift.stop();
  } else {
    lift.spin(reverse);
  }

  liftdown = !liftdown;
}

void lift_exact() {
  // Brain.Screen.clearScreen();
  // Brain.Screen.setCursor(1, 1);
  // Brain.Screen.print("lift did something :)");
  // trial and error
  int angle = 185;
  if (liftexact) {
    lift.spinFor(forward, angle, degrees);
  } else {
    lift.spinFor(reverse, angle, degrees);
  }

  liftexact = !liftexact;
}

void arm_up() {
  // Brain.Screen.clearScreen();
  // Brain.Screen.setCursor(1, 1);
  // Brain.Screen.print("arm up");
  arm.spin(forward);
}

void arm_down() {
  // Brain.Screen.clearScreen();
  // Brain.Screen.setCursor(1, 1);
  // Brain.Screen.print("arm down");
  arm.spin(reverse);
}

void arm_stop() {
  // Brain.Screen.clearScreen();
  // Brain.Screen.setCursor(1, 1);
  // Brain.Screen.print("arm stop");
  arm.stop();
}

void drive_init() {
  Drivetrain.setDriveVelocity(60, percent);

  claw.setVelocity(50, percent);
  claw.setStopping(hold);
  // claw.setMaxTorque(100, percent);

  hoover.setVelocity(100, percent);
  // hoover.setMaxTorque(100, percent);

  lift.setVelocity(10, percent);
  lift.setStopping(hold);
  lift.setPosition(0, degrees);
  // lift.setMaxTorque(100, percent);

  arm.setVelocity(40, percent);
  arm.setStopping(hold);
  arm.setPosition(0, degrees);
  // arm.setMaxTorque(100, percent);



  Controller2.ButtonUp.pressed(arm_down);
  Controller2.ButtonUp.released(arm_stop);
  Controller2.ButtonDown.pressed(arm_up);
  Controller2.ButtonDown.released(arm_stop);

  Controller2.ButtonY.pressed(grip_toggle);
  Controller2.ButtonA.pressed(intake_toggle);
  // Controller1.ButtonX.pressed(lift_up);
  // Controller1.ButtonB.pressed(lift_down);
  Controller2.ButtonB.pressed(lift_exact);
}
