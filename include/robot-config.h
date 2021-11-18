using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern drivetrain Drivetrain;
extern controller Controller1;
extern signature Vision19__SIG_1;
extern signature Vision19__SIG_2;
extern signature Vision19__SIG_3;
extern signature Vision19__SIG_4;
extern signature Vision19__SIG_5;
extern signature Vision19__SIG_6;
extern signature Vision19__SIG_7;
extern vision Vision19;
extern signature Vision20__DONUT;
extern signature Vision20__SIG_2;
extern signature Vision20__SIG_3;
extern signature Vision20__SIG_4;
extern signature Vision20__SIG_5;
extern signature Vision20__SIG_6;
extern signature Vision20__SIG_7;
extern vision Vision20;
extern bumper BumperA;
extern bumper BumperB;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );