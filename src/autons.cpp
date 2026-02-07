#include "main.h"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 90;
const int SWING_SPEED = 110;

// Turn to 45deg with the left side of the drive


void test(){
  chassis.pid_swing_set(ez::LEFT_SWING, 180_deg, 80);
  chassis.pid_wait();
}

// Def. Constants
void default_constants() {
  // P, I, D, and Start I
  chassis.pid_drive_constants_set(20.0, 0.0, 100.0);         // Fwd/rev constants, used for odom and non odom motions
  chassis.pid_heading_constants_set(11.0, 0.0, 20.0);        // Holds the robot straight while going forward without odom
  chassis.pid_turn_constants_set(3.0, 0.05, 20.0, 15.0);     // Turn in place constants
  chassis.pid_swing_constants_set(6.0, 0.0, 65.0);           // Swing constants
  chassis.pid_odom_angular_constants_set(6.5, 0.0, 52.5);    // Angular control for odom motions
  chassis.pid_odom_boomerang_constants_set(5.8, 0.0, 32.5);  // Angular control for boomerang motions

  // Exit conditions
  chassis.pid_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
  chassis.pid_odom_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 750_ms);
  chassis.pid_odom_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 750_ms);
  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  // Slew constants
  chassis.slew_turn_constants_set(3_deg, 70);
  chassis.slew_drive_constants_set(3_in, 70);
  chassis.slew_swing_constants_set(3_in, 80);

  // The amount that turns are prioritized over driving in odom motions
  // - if you have tracking wheels, you can run this higher.  1.0 is the max
  chassis.odom_turn_bias_set(0.9);

  chassis.odom_look_ahead_set(7_in);           // This is how far ahead in the path the robot looks at
  chassis.odom_boomerang_distance_set(16_in);  // This sets the maximum distance away from target that the carrot point can be
  chassis.odom_boomerang_dlead_set(0.625);     // This handles how aggressive the end of boomerang motions are

  chassis.pid_angle_behavior_set(ez::shortest);  // Changes the default behavior for turning, this defaults it to the shortest path there
}

// Left Side
void middleGoal() {
  //Left Auton
  //Initialization
  chassis.slew_drive_set(true);  // Enables global slew
  chassis.slew_drive_constants_set(5_in, 50);
  chassis.slew_turn_set(true);  // Enables global slew
  chassis.slew_turn_constants_set(5_deg, 50);


  //Move 16.5 inches forward
  chassis.pid_drive_set(16.5_in, 110);
  chassis.pid_wait();
  //Turn 90 Left 
  chassis.pid_turn_set(270_deg, 90);
  chassis.pid_wait();
  //Forward 8
  chassis.pid_drive_set(7.75_in, 110);
  chassis.pid_wait();
  //Turn 90 Right
  chassis.pid_turn_set(0_deg, 100);
  chassis.pid_wait();
  //Forward 24 inches 
  intake.move(100);

  chassis.pid_drive_set(28_in, 20,false);
  chassis.pid_wait();
  
  pros::delay(1000);

  intake.move(0);
  chassis.pid_drive_set(-10_in, 110,false);
  chassis.pid_wait();
  //Turn 135 left 
  chassis.pid_turn_set(225_deg, 100);
  chassis.pid_wait();
  //Back 15 inches
  chassis.pid_drive_set(-13_in, 110);
  chassis.pid_wait();

  intake.move(120);
  scorer.move(-60);
}

void elimLongGoalLeft() {
  //Left Auton
  //Initialization
  chassis.slew_drive_set(true);  // Enables global slew
  chassis.slew_drive_constants_set(5_in, 50);
  chassis.slew_turn_set(true);  // Enables global slew
  chassis.slew_turn_constants_set(5_deg, 50);


  //Move 16.5 inches forward
  chassis.pid_drive_set(16.5_in, 110);
  chassis.pid_wait();
  //Turn 90 Left 
  chassis.pid_turn_set(270_deg, 90);
  chassis.pid_wait();
  //Forward 8
  chassis.pid_drive_set(8_in, 110);
  chassis.pid_wait();
  //Turn 90 Right
  chassis.pid_turn_set(0_deg, 100);
  chassis.pid_wait();
  //Forward 24 inches 
  intake.move(100);

  chassis.pid_drive_set(28_in, 40,false);
  chassis.pid_wait();
  
  pros::delay(1000);

  intake.move(0);
  chassis.pid_drive_set(-10_in, 110,false);
  chassis.pid_wait();
  //Turn 135 left 
  chassis.pid_turn_set(45_deg, 120);
  chassis.pid_wait();
  //Back 15 inches
  chassis.pid_drive_set(-26.5_in, 80);
  chassis.pid_wait();
  pros::delay(100);

  chassis.pid_turn_set(180_deg, 80);
  chassis.pid_wait();

  loader.set(true);  
  pros::delay(500);

  chassis.pid_drive_set(13_in, 127);
  chassis.pid_wait();

  intake.move(70);
  pros::delay(1000);

  chassis.pid_drive_set(-2, 127);
  chassis.pid_wait();

  chassis.pid_drive_set(2, 127);
    chassis.pid_wait();

  chassis.pid_drive_set(-10_in, 127);
  chassis.pid_wait();

  // chassis.pid_turn_set(90_deg, 80);
  // chassis.pid_wait();

  // chassis.pid_drive_set(-1_in, 127);
  // chassis.pid_wait();

  // chassis.pid_turn_set(180_deg, 80);
  // chassis.pid_wait();

  chassis.pid_drive_set(-12_in, 127);
  chassis.pid_wait();


  // chassis.pid_turn_set(-90, 110);
  // chassis.pid_wait();

  //  chassis.pid_drive_set(1_in, 120);
  // chassis.pid_wait();

  // chassis.pid_turn_set(180_deg, 110);
  // chassis.pid_wait();

  intake.move(120);
  scorer.move(120);
}

void controlZoneLeftLongGoal(){
//Left Auton
  //Initialization
  chassis.slew_drive_set(true);  // Enables global slew
  chassis.slew_drive_constants_set(5_in, 50);
  chassis.slew_turn_set(true);  // Enables global slew
  chassis.slew_turn_constants_set(5_deg, 50);


  //Move 16.5 inches forward
  chassis.pid_drive_set(16.5_in, 120);
  chassis.pid_wait();
  //Turn 90 Left 
  chassis.pid_turn_set(270_deg, 100);
  chassis.pid_wait();
  //Forward 8
    // TUNE START ***************************************

  chassis.pid_drive_set(30_in, 120);
  chassis.pid_wait();
  // TUNE END ***************************************

   loader.set(true);  
  pros::delay(200);
    chassis.pid_turn_set(180_deg, 100);
  chassis.pid_wait();
  // TUNE START ***************************************


  chassis.pid_drive_set(16_in, 120);
  chassis.pid_wait();

  intake.move(70);
  pros::delay(700);

  chassis.pid_drive_set(-10_in, 127);
  chassis.pid_wait();

  // chassis.pid_turn_set(90_deg, 80);
  // chassis.pid_wait();

  // chassis.pid_drive_set(-1_in, 127);
  // chassis.pid_wait();

  // chassis.pid_turn_set(180_deg, 80);
  // chassis.pid_wait();

  chassis.pid_drive_set(-12_in, 127);
  chassis.pid_wait(); 
  // TUNE END ***************************************
//long goal
  intake.move(127);
  scorer.move(127);
// Add control zone push
  pros::delay(4000);
    intake.move(0);
  scorer.move(0);
    loader.set(false);  
  chassis.pid_drive_set(5_in, 120, false);
  chassis.pid_wait();

     chassis.pid_turn_set(90_deg, 100, false);
  chassis.pid_wait();
  chassis.pid_drive_set(7.5_in, 120, false);
  chassis.pid_wait();

       chassis.pid_turn_set(0_deg, 110);
  chassis.pid_wait();

  chassis.pid_drive_set(30_in, 110, false);
  chassis.pid_wait(); 

   chassis.pid_turn_set(0_deg, 100);
  chassis.pid_wait();


}

void middleLongGoal(){
  chassis.slew_drive_set(true);
  chassis.slew_turn_set(true);

  chassis.slew_drive_set(true);  // Enables global slew
  chassis.slew_drive_constants_set(5_in, 50);
  chassis.slew_turn_set(true);  // Enables global slew
  chassis.slew_turn_constants_set(5_deg, 50);


  //Move 16.5 inches forward
  chassis.pid_drive_set(16.5_in, 110);
  chassis.pid_wait();
  //Turn 90 Left 
  chassis.pid_turn_set(270_deg, 100);
  chassis.pid_wait();
  //Forward 8
  chassis.pid_drive_set(8_in, 110);
  chassis.pid_wait();
  //Turn 90 Right
  chassis.pid_turn_set(0_deg, 110);
  chassis.pid_wait();
  //Forward 24 inches 
  intake.move(70);

  chassis.pid_drive_set(25_in, 40,false);
  chassis.pid_wait();
  
  pros::delay(1000);

  intake.move(0);
  chassis.pid_drive_set(-7_in, 120,false);
  chassis.pid_wait();
  //Turn 135 left 
  chassis.pid_turn_set(225_deg, 120);
  chassis.pid_wait();
  //Back 15 inches
  chassis.pid_drive_set(-16_in, 120);
  chassis.pid_wait();

  intake.move(120);
  scorer.move(-60);

  pros::delay(2000);
  
  intake.move(0);
  scorer.move(0);

  chassis.pid_drive_set(50_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();
// Load
  pros::delay(2000);

  chassis.pid_drive_set(14_in, DRIVE_SPEED);
  chassis.pid_wait();
  pros::delay(1500);

  // 12. Go back toward long goal
  chassis.pid_drive_set(-14_in, DRIVE_SPEED);
  chassis.pid_wait();

  // 13. Score blocks in Long Goal
  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();
  scorer.move(127);
  
}

// Right Side
void controlZoneRightLongGoal(){
  //Initialization
  chassis.slew_drive_set(true);  // Enables global slew
  chassis.slew_drive_constants_set(5_in, 50);
  chassis.slew_turn_set(true);  // Enables global slew
  chassis.slew_turn_constants_set(5_deg, 50);


  //Move 16.5 inches forward
  chassis.pid_drive_set(16.5_in, 120);
  chassis.pid_wait();
  //Turn 90 Left 
  chassis.pid_turn_set(90_deg, 100);
  chassis.pid_wait();
  //Forward 8
    // TUNE START ***************************************

  chassis.pid_drive_set(33_in, 120);
  chassis.pid_wait();
  // TUNE END ***************************************

   loader.set(true);  
  pros::delay(200);
    chassis.pid_turn_set(180_deg, 100);
  chassis.pid_wait();
  // TUNE START ***************************************


  chassis.pid_drive_set(15.5_in, 120);
  chassis.pid_wait();

  intake.move(70);
  pros::delay(700);

  chassis.pid_drive_set(-23_in, 127);
  chassis.pid_wait();

  // chassis.pid_turn_set(90_deg, 80);
  // chassis.pid_wait();

  // chassis.pid_drive_set(-1_in, 127);
  // chassis.pid_wait();

  // chassis.pid_turn_set(180_deg, 80);
  // chassis.pid_wait();

  // TUNE END ***************************************
//long goal
  intake.move(127);
  scorer.move(127);
// Add control zone push
  pros::delay(4000);
    intake.move(0);
  scorer.move(0);
    loader.set(false);  
  chassis.pid_drive_set(5_in, 120);
  chassis.pid_wait();

     chassis.pid_turn_set(90_deg, 90);
  chassis.pid_wait();
  chassis.pid_drive_set(-8.1_in, 90);
  chassis.pid_wait();

       chassis.pid_turn_set(180_deg, 100);
  chassis.pid_wait();

  chassis.pid_drive_set(-29_in, 80, false);
  chassis.pid_wait(); 

   chassis.pid_turn_set(180_deg, 90);
  chassis.pid_wait();


}

void elimLongGoalRight(){
  //Do after tuning
}

// Major Match
void soloAWP(){
  // Big auton! do it last
}

// Skills
void skills(){
chassis.slew_drive_set(true);  // Enables global slew
  chassis.slew_drive_constants_set(5_in, 50);
  chassis.slew_turn_set(true);  // Enables global slew
  chassis.slew_turn_constants_set(5_deg, 50);


  //Move 16.5 inches forward
  chassis.pid_drive_set(16.5_in, 120);
  chassis.pid_wait();
  //Turn 90 Left 
  chassis.pid_turn_set(270_deg, 90);
  chassis.pid_wait();
  //Forward 8
    // TUNE START ***************************************

  chassis.pid_drive_set(28.5_in, 120);
  chassis.pid_wait();
  // TUNE END ***************************************

   loader.set(true);  
  pros::delay(500);


    chassis.pid_turn_set(180_deg, 100);
  chassis.pid_wait();


  chassis.pid_drive_set(18_in, 50);
  chassis.pid_wait();

  intake.move(120);
  pros::delay(3500);
 


 chassis.pid_drive_set(-2_in, 100);
  chassis.pid_wait();
  pros::delay(100);

    chassis.pid_drive_set(2_in, 100);
  chassis.pid_wait();
  pros::delay(100);

  
  intake.move(0);
  scorer.move(0);

  chassis.pid_drive_set(-15.5_in, 60);
  chassis.pid_wait();

  // chassis.pid_turn_set(90_deg, 80);
  // chassis.pid_wait();

  // chassis.pid_drive_set(-1_in, 127);
  // chassis.pid_wait();

  // chassis.pid_turn_set(180_deg, 80);
  // chassis.pid_wait();

 
// Add control zone push
   

  chassis.pid_turn_set(270_deg, 90);
  chassis.pid_wait();

  chassis.pid_drive_set(-95_in, 80);
  chassis.pid_wait();

    // loader.set(false);  
    chassis.pid_turn_set(180_deg, 90);
  chassis.pid_wait();

   chassis.pid_drive_set(-4.5_in, 60);
  chassis.pid_wait(); 

//long goal
  intake.move(127);
  scorer.move(127);
  pros::delay(6000);
 
  loader.set(true);  
  pros::delay(500);

  intake.move(0);
  scorer.move(0);
  

  chassis.pid_drive_set(25_in, 50);
  chassis.pid_wait();

  intake.move(120);
  pros::delay(5000);

   intake.move(0);
  scorer.move(0);

   chassis.pid_drive_set(-23_in, 50);
  chassis.pid_wait();

   
    chassis.pid_turn_set(180_deg, 100);
  chassis.pid_wait();

  intake.move(127);
  scorer.move(127);
  pros::delay(6000);
  loader.set(false);  
intake.move(0);
  scorer.move(0);
  chassis.pid_drive_set(10_in, 100);
  chassis.pid_wait();
 chassis.pid_turn_set(90_deg, 100);
  chassis.pid_wait();
   chassis.pid_drive_set(-40_in, 100);
  chassis.pid_wait();
  chassis.pid_turn_set(0_deg, 100);
  chassis.pid_wait();

  chassis.pid_drive_set(-20_in, 100);
  chassis.pid_wait();

   chassis.pid_turn_set(0_deg, 100);
  chassis.pid_wait();

    chassis.pid_drive_set(-5_in, 100);
  chassis.pid_wait();


}