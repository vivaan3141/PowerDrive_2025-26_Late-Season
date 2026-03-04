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

void lowLong(){
chassis.slew_drive_set(true);  // Enables global slew
  chassis.slew_drive_constants_set(3_in, 60);
  chassis.slew_turn_set(true);  // Enables global slew
  chassis.slew_turn_constants_set(3_deg, 60);
  //Initialize as 270
  chassis.drive_angle_set(90_deg); 
  
  chassis.pid_swing_set(ez::RIGHT_SWING, 30, 110); 
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(0_deg, 127);
  chassis.pid_wait_quick_chain();
  intake.move(127);

  chassis.pid_drive_set(15_in, 127);
  chassis.pid_wait_quick();

  loader.set(true);  
  pros::delay(500);

  chassis.pid_drive_set(13_in, 127);
  chassis.pid_wait_quick();

 chassis.pid_drive_set(-2_in, 127,false);
  chassis.pid_wait();
  loader.set(false);  
  intake.move(0);
  intake.move(-50);

  //Turn 135 left 
  chassis.pid_turn_set(-43_deg, 127, false);
  chassis.pid_wait();
  //Back 15 inches

  chassis.pid_drive_set(15_in, 127);
  chassis.pid_wait();
  intake.move(0);


  intake.move(-127);
  pros::delay(2000);
  

  // long goal
// intake.move(0);
//    chassis.pid_drive_set(-40_in, 90);
//   chassis.pid_wait();
//    chassis.pid_swing_set(ez::LEFT_SWING, 3, 110); 
//   chassis.pid_wait_quick_chain();
//   loader.set(true);  
//   pros::delay(250);
//   chassis.pid_turn_set(180_deg, 127, false);
//   chassis.pid_wait();

//   chassis.pid_drive_set(10_in, 80);
//   chassis.pid_wait();

//   intake.move(100);
//   pros::delay(400);


//   chassis.pid_turn_set(180_deg, 80); // Safety Turn
//   chassis.pid_wait();
//     intake.move(127);

//   chassis.pid_drive_set(-23_in, 127);
//   chassis.pid_wait(); 
//     intake.move(127);

//  chassis.pid_turn_set(180_deg, 127, false);
//   chassis.pid_wait();
//   loader.set(false);  
//   // TUNE END ***************************************
// //long goal
//   scorer.move(127);




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
  chassis.pid_drive_set(-16_in, 110);
  chassis.pid_wait();

  intake.move(120);
  scorer.move(-60);
}

void elimLongGoalLeft() {
  chassis.slew_drive_set(true);  // Enables global slew
  chassis.slew_drive_constants_set(3_in, 60);
  chassis.slew_turn_set(true);  // Enables global slew
  chassis.slew_turn_constants_set(3_deg, 60);
  //Initialize as 270
  chassis.drive_angle_set(270_deg); 
  
  chassis.pid_swing_set(ez::LEFT_SWING, -35, 110); 
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(2_deg, 127);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(14.5_in, 127);
  chassis.pid_wait_quick();
  intake.move(127);

  loader.set(true);  
  pros::delay(500);

  chassis.pid_drive_set(11.5_in, 127);
  chassis.pid_wait_quick();

 chassis.pid_drive_set(-2_in, 127,false);
  chassis.pid_wait();
  //Turn 135 left 
  chassis.pid_turn_set(225_deg, 127, false);
  chassis.pid_wait();
  //Back 15 inches
 
   chassis.pid_drive_set(34_in, 90);
  chassis.pid_wait();
  loader.set(true);  
  pros::delay(250);
  chassis.pid_turn_set(180_deg, 127, false);
  chassis.pid_wait();

  chassis.pid_drive_set(16_in, 70);
  chassis.pid_wait();

  intake.move(100);
  pros::delay(300);


  chassis.pid_turn_set(180_deg, 80); // Safety Turn
  chassis.pid_wait();
    intake.move(127);

  chassis.pid_drive_set(-22.5_in, 127);
  chassis.pid_wait(); 
    intake.move(127);

 chassis.pid_turn_set(180_deg, 127, false);
  chassis.pid_wait();
  loader.set(false);  
  // TUNE END ***************************************
//long goal
  scorer.move(127);




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

  chassis.pid_drive_set(29_in, 120);
  chassis.pid_wait();
  // TUNE END ***************************************

   loader.set(true);  
  pros::delay(300);
    chassis.pid_turn_set(180_deg, 100);
  chassis.pid_wait();
  // TUNE START ***************************************


  chassis.pid_drive_set(16_in, 100);
  chassis.pid_wait();

  intake.move(70);
  pros::delay(600);

  chassis.pid_drive_set(-10_in, 127);
  chassis.pid_wait();

  // chassis.pid_turn_set(90_deg, 80);
  // chassis.pid_wait();

  // chassis.pid_drive_set(-1_in, 127);
  // chassis.pid_wait();

  // chassis.pid_turn_set(180_deg, 80);
  // chassis.pid_wait();

  chassis.pid_drive_set(-13_in, 127);
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

  chassis.pid_drive_set(30_in, 100, false);
  chassis.pid_wait(); 

   chassis.pid_turn_set(0_deg, 100);
  chassis.pid_wait();


}

void middleLongGoal(){

  chassis.slew_drive_set(true);  // Enables global slew
  chassis.slew_drive_constants_set(3_in, 60);
  chassis.slew_turn_set(true);  // Enables global slew
  chassis.slew_turn_constants_set(3_deg, 60);
  //Initialize as 270
  chassis.drive_angle_set(270_deg); 
  
  chassis.pid_swing_set(ez::LEFT_SWING, -35, 110); 
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(2_deg, 127);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(13_in, 127);
  chassis.pid_wait_quick();
  intake.move(127);

  loader.set(true);  
  pros::delay(500);

  chassis.pid_drive_set(15_in, 127);
  chassis.pid_wait_quick();

 chassis.pid_drive_set(-6.5_in, 127,false);
  chassis.pid_wait();
  //Turn 135 left 
  chassis.pid_turn_set(225_deg, 127, false);
  chassis.pid_wait();
  //Back 15 inches
  chassis.pid_drive_set(-14.75_in, 127);
  chassis.pid_wait();
  intake.move(0);


  intake.move(127);
  scorer.move(-127);
  loader.set(false);  
  pros::delay(1500);

  // long goal
intake.move(0);
  scorer.move(0);
   chassis.pid_drive_set(47.25_in, 90);
  chassis.pid_wait();
  loader.set(true);  
  pros::delay(250);
  chassis.pid_turn_set(180_deg, 127, false);
  chassis.pid_wait();

  chassis.pid_drive_set(14_in, 80);
  chassis.pid_wait();

  intake.move(100);
  pros::delay(400);


  chassis.pid_turn_set(180_deg, 80); // Safety Turn
  chassis.pid_wait();
    intake.move(127);

  chassis.pid_drive_set(-23.25_in, 127);
  chassis.pid_wait(); 
    intake.move(127);

 chassis.pid_turn_set(180_deg, 127, false);
  chassis.pid_wait();
  loader.set(false);  
  // TUNE END ***************************************
//long goal
  scorer.move(127);








}



void BmiddleLongGoal(){
  chassis.slew_drive_set(true);  // Enables global slew
  chassis.slew_drive_constants_set(3_in, 60);
  chassis.slew_turn_set(true);  // Enables global slew
  chassis.slew_turn_constants_set(3_deg, 60);
  //Initialize as 270
  chassis.drive_angle_set(270_deg); 
  
  chassis.pid_swing_set(ez::LEFT_SWING, -35, 120); 
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(2_deg, 127);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(15_in, 127);
  chassis.pid_wait_quick_chain();
  intake.move(127);
  scorer.move(0);

  loader.set(true);  
  pros::delay(500);

  chassis.pid_drive_set(15_in, 127);
  chassis.pid_wait_quick_chain();

 chassis.pid_drive_set(-12_in, 127,false);
  chassis.pid_wait();
  //Turn 135 left 
  chassis.pid_turn_set(225_deg, 127, false);
  chassis.pid_wait();
  //Back 15 inches
  chassis.pid_drive_set(-15.5_in, 127);
  chassis.pid_wait();
  intake.move(0);


  intake.move(127);
  scorer.move(-127);
  pros::delay(1500);

  // long goal
intake.move(0);
  scorer.move(0);
    loader.set(true);  

   chassis.pid_drive_set(46.5_in, 90);
  chassis.pid_wait();
  // pros::delay(250);
  chassis.pid_turn_set(180_deg, 127, false);
  chassis.pid_wait();
  intake.move(127);

  chassis.pid_drive_set(9.5_in, 80);
  chassis.pid_wait();

  pros::delay(450);


  chassis.pid_drive_set(-18.8_in, 127);
  chassis.pid_wait_quick_chain();

 chassis.pid_turn_set(180_deg, 127, false);
  chassis.pid_wait();
  loader.set(false);  
  // TUNE END ***************************************
//long goal
  scorer.move(127);
   pros::delay(2000);
    intake.move(0);
  scorer.move(0);
  chassis.pid_drive_set(5_in, 127, false);
  chassis.pid_wait_quick_chain();

     chassis.pid_turn_set(90_deg, 127, false);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(7_in, 127, false);
  chassis.pid_wait_quick();

       chassis.pid_turn_set(0_deg, 127);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(30_in, 60, false);
  chassis.pid_wait_quick_chain();

   chassis.pid_turn_set(0_deg, 127);
  chassis.pid_wait_quick_chain();


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

  chassis.pid_drive_set(33_in, 70);
  chassis.pid_wait();
  // TUNE END ***************************************

   loader.set(true);  
  pros::delay(200);
    chassis.pid_turn_set(180_deg, 90);
  chassis.pid_wait();
  // TUNE START ***************************************


  chassis.pid_drive_set(15.5_in, 90);
  chassis.pid_wait();

  intake.move(70);
  pros::delay(600);

  chassis.pid_drive_set(-23_in, 90);
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
  chassis.pid_drive_set(5_in, 90);
  chassis.pid_wait();

  chassis.pid_turn_set(90_deg, 90);
  chassis.pid_wait();
  chassis.pid_drive_set(-7.5_in, 90);
  chassis.pid_wait();

       chassis.pid_turn_set(180_deg, 90);
  chassis.pid_wait();

  chassis.pid_drive_set(-27.5_in, 80, false);
  chassis.pid_wait(); 

   chassis.pid_turn_set(180_deg, 90);
  chassis.pid_wait();


}

void elimLongGoalRight(){
chassis.slew_drive_set(true);  // Enables global slew
  chassis.slew_drive_constants_set(3_in, 60);
  chassis.slew_turn_set(true);  // Enables global slew
  chassis.slew_turn_constants_set(3_deg, 60);
  //Initialize as 270
  chassis.drive_angle_set(90_deg); 
  
  chassis.pid_swing_set(ez::RIGHT_SWING, 35, 110); 
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(-2_deg, 127);
  chassis.pid_wait_quick_chain();

  intake.move(127);
  chassis.pid_drive_set(15.5_in, 60);
  chassis.pid_wait_quick();

  loader.set(true);  
  pros::delay(400);

  chassis.pid_drive_set(13.5_in, 127);
  chassis.pid_wait_quick();
  
  chassis.pid_turn_set(135_deg, 127, false);
  chassis.pid_wait();
  //Back 15 inches
 
   chassis.pid_drive_set(38.5_in, 90);
  chassis.pid_wait();
  // loader.set(true);  
  // pros::delay(220);
  chassis.pid_turn_set(180_deg, 127, false);
  chassis.pid_wait();
    intake.move(127);


  chassis.pid_drive_set(14.5_in, 80);
  chassis.pid_wait();

  pros::delay(300);
  intake.move(0);


  chassis.pid_turn_set(180_deg, 80); // Safety Turn
  chassis.pid_wait();

  chassis.pid_drive_set(-22.75_in, 127);
  chassis.pid_wait(); 
    intake.move(127);

 chassis.pid_turn_set(180_deg, 127, false);
  chassis.pid_wait();
  loader.set(false);  
  scorer.move(127);
}

// Major Match

void StateSkills(){
  chassis.slew_drive_set(true);  // Enables global slew
  chassis.slew_drive_constants_set(5_in, 50);
  chassis.slew_turn_set(true);  // Enables global slew
  chassis.slew_turn_constants_set(5_deg, 50);

  //set heading
  chassis.drive_angle_set(180_deg);


  chassis.pid_drive_set(29.5_in, 50.5);
  chassis.pid_wait();
  loader.set (true);

  chassis.pid_turn_set(270_deg, 60);
  chassis.pid_wait();
  pros::delay (500);

  //drive to matchlaoder

  chassis.pid_drive_set(10.5_in, 63.5);
  chassis.pid_wait();

  //intake from matchloader
  intake.move(127);
  pros::delay(2500);
  intake.move(0);

   chassis.pid_drive_set(-10.5_in, 63.5);
  chassis.pid_wait();
    loader.set (false);

    pros::delay(200);

    chassis.pid_turn_set(315_deg, 60);
  chassis.pid_wait();
  pros::delay (500);

  
   chassis.pid_drive_set(-16_in, 63.5);
  chassis.pid_wait();

chassis.pid_swing_set(ez::LEFT_SWING, 270, 120); 
  chassis.pid_wait();
    pros::delay(200);

     chassis.pid_drive_set(-59_in, 63.5);
  chassis.pid_wait();

      pros::delay(200);
chassis.pid_swing_set(ez::LEFT_SWING, 225, 120); 
  chassis.pid_wait();
    pros::delay(200);
     chassis.pid_drive_set(-18_in, 63.5);
  chassis.pid_wait();
    pros::delay(200);
      chassis.pid_turn_set(90_deg, 60);
  chassis.pid_wait();
  pros::delay (500);

     chassis.pid_drive_set(-14.15_in, 63.5);
  chassis.pid_wait();
    pros::delay(200);

     intake.move (127); //scoreTop
    scorer.move (127);
    pros::delay(3000);
      scorer.move (0);
     intake.move (0); 

  loader.set (true);

  chassis.pid_drive_set(26_in, 63.5); //going to match loader 2 pt2; og 22 -2/12
  chassis.pid_wait();

  //intake from matchloader

  intake.move (127);

  pros::delay (3000); // picked up from first match loader
  intake.move (0);

  //drive to long goal
  chassis.pid_drive_set(-24.5_in, 63.5); //backing to goal to score match loader 2
  chassis.pid_wait();

  intake.move (127); //scoreTop
    scorer.move (127);

  pros::delay (3000); // picked up from first match loader
    scorer.move (0);

   chassis.pid_drive_set(6_in, 63.5); //backing to goal to score match loader 2
  chassis.pid_wait();

    chassis.pid_turn_set(180_deg, 60);
  chassis.pid_wait();
  pros::delay (200); // picked up from first match loader

     chassis.pid_drive_set(-95.5_in, 63.5); //backing to goal to score match loader 2
  chassis.pid_wait();

      chassis.pid_turn_set(90_deg, 60);
  chassis.pid_wait();

    loader.set (true);

   chassis.pid_drive_set(18.5_in, 63.5); //backing to goal to score match loader 2
  chassis.pid_wait();

  intake.move (127);
  scorer.move (0);

  pros::delay (3000); // picked up from first match loader
  intake.move (0);

  //drive to long goal
  chassis.pid_drive_set(-12_in, 63.5); //backing to goal to score match loader 2
  chassis.pid_wait();
   chassis.pid_turn_set(90_deg, 60);
  chassis.pid_wait();
  chassis.pid_drive_set(-11.5_in, 63.5); //backing to goal to score match loader 2
  chassis.pid_wait();

  intake.move (127); //scoreTop
    scorer.move (127);
  pros::delay (3000); // picked up from first match loader
      loader.set (false);
 intake.move (0); //scoreTop
    scorer.move (0);


    // ------------------------------------------------------------- //

  chassis.pid_drive_set(16_in, 63.5);
  chassis.pid_wait();

    pros::delay(200);

    chassis.pid_turn_set(135_deg, 60);
  chassis.pid_wait();
  pros::delay (500);

  
   chassis.pid_drive_set(-16_in, 63.5);
  chassis.pid_wait();

chassis.pid_swing_set(ez::LEFT_SWING, 90, 120); 
  chassis.pid_wait();
    pros::delay(200);

     chassis.pid_drive_set(-59_in, 63.5);
  chassis.pid_wait();

      pros::delay(200);
chassis.pid_swing_set(ez::LEFT_SWING, 45, 120); 
  chassis.pid_wait();
    pros::delay(200);
  //    chassis.pid_drive_set(-18_in, 63.5);
  // chassis.pid_wait();
  //   pros::delay(200);
  //     chassis.pid_turn_set(270_deg, 60);

}

void skills(){
  //initialize
  chassis.slew_drive_set(true);  // Enables global slew
  chassis.slew_drive_constants_set(5_in, 50);
  chassis.slew_turn_set(true);  // Enables global slew
  chassis.slew_turn_constants_set(5_deg, 50);

  //set heading
  chassis.drive_angle_set(180_deg);

  //turn to matchloader
  chassis.pid_drive_set(30_in, 63.5);
  chassis.pid_wait();
  loader.set (true);

  chassis.pid_turn_set(270_deg, 60);
  chassis.pid_wait();
  pros::delay (500);

  //drive to matchlaoder

  chassis.pid_drive_set(10.5_in, 63.5);
  chassis.pid_wait();

  //intake from matchloader
  intake.move(127);
  pros::delay(2500);
  intake.move(0);


  chassis.pid_drive_set(-13.5_in, 63.5);
  chassis.pid_wait();

  chassis.pid_turn_set(180_deg, 45);
  chassis.pid_wait();

  //scraper.set (false); might help with getting all blocks
  //pros::delay (1000);

  //conveyor.move (0);

  //drive to other side
  //chassis.pid_turn_relative_set(180, 60);
  //chassis.pid_turn_set(270_deg, 60);
  //chassis.pid_wait();
  chassis.pid_drive_set(-91.5_in, 50);
  chassis.pid_wait();

  //drive to long goal
  chassis.pid_turn_set(270, 60);
  chassis.pid_wait();

  pros::delay (500);
  chassis.pid_drive_set(-9_in, 50); //og -18 -2/12
  chassis.pid_wait();

  intake.move (127); //scoreTop
    scorer.move (127);

  pros::delay (3000); // scored first match loader

intake.move (-60); //scoreTop
  pros::delay (1000); // scored first match loader
intake.move (127); //scoreTop
    scorer.move (127);
      pros::delay (3000); // scored first match loader
  //prep for matchloader
  //scraper.set (true); removed b/c never closed above
  intake.move (0); //stopAll
  scorer.move (0); //stopAll

  //drive to matchloader 2
  // chassis.pid_drive_set(4_in, 63.5); //going to match loader 2 pt 1
  // chassis.pid_wait();
  chassis.pid_turn_set(270, 60);
  chassis.pid_wait();
  chassis.pid_drive_set(26.4_in, 63.5); //going to match loader 2 pt2; og 22 -2/12
  chassis.pid_wait();

  //intake from matchloader

  intake.move (127);

  pros::delay (3000); // picked up from first match loader
  intake.move (0);



  //drive to long goal
  chassis.pid_drive_set(-24_in, 63.5); //backing to goal to score match loader 2
  chassis.pid_wait();

  intake.move (127); //scoreTop
    scorer.move (127);

  pros::delay (3000); // scored first match loader

intake.move (-60); //scoreTop
  pros::delay (1000); // scored first match loader
intake.move (127); //scoreTop
    scorer.move (127);
      pros::delay (3000); // scored first match loader
  //prep for matchloader
  //scraper.set (true); removed b/c never closed above
  intake.move (0); //stopAll
  scorer.move (0); //stopAll

  loader.set (false);
  pros::delay (1000);
  intake.move (0); //stopAll
  scorer.move (0); //stopAll
  pros::delay (500);


  // chassis.drive_angle_set(90_deg); 
  intake.move (127); //scoreTop
    scorer.move (127);
  pros::delay (5000); // scored first match loader

  chassis.pid_drive_set(6_in, 63.5);
  chassis.pid_wait();
  chassis.pid_turn_set(180_deg, 80);
    chassis.pid_wait();
  chassis.pid_drive_set(50_in, 63.5);
  chassis.pid_wait();
   chassis.pid_turn_set(-90_deg, 60);
    chassis.pid_wait();


  pros::delay (1000);
  chassis.pid_drive_set(-15, 127,false);
  chassis.pid_wait();
  pros::delay (1000);
  chassis.pid_drive_set(60, 127,false);
  chassis.pid_wait();
  pros::delay (1000);




/*

  //Old park
  chassis.pid_drive_set(8_in, 63.5);
  chassis.pid_wait();
  chassis.pid_turn_set(225_deg, 60);
  chassis.pid_wait();
  chassis.pid_drive_set(-25_in, 63.5);
  chassis.pid_wait();
  chassis.pid_swing_set(ez::LEFT_SWING, 185, 90);  chassis.pid_wait();
  
  chassis.pid_drive_set(10_in, 127,false);
  chassis.pid_wait();
  
  pros::delay (1000);

  chassis.pid_drive_set(-55_in, 127,false);
  chassis.pid_wait();
*/ 

}

void Gpark(){
  chassis.slew_drive_set(true);  // Enables global slew
  chassis.slew_drive_constants_set(5_in, 50);
  chassis.slew_turn_set(true);  // Enables global slew
  chassis.slew_turn_constants_set(5_deg, 50);

  //set heading
  chassis.drive_angle_set(-90_deg);
  loader.set (false);
  pros::delay (1000);
  intake.move (0); //stopAll
  scorer.move (0); //stopAll
  pros::delay (500);


  chassis.drive_angle_set(90_deg); 
  intake.move (127); //scoreTop
    scorer.move (127);
  pros::delay (5000); // scored first match loader

  chassis.pid_drive_set(8_in, 63.5);
  chassis.pid_wait();
  chassis.pid_turn_set(45_deg, 60);
  chassis.pid_drive_set(28_in, 63.5);
  chassis.pid_wait();
  chassis.pid_swing_set(ez::RIGHT_SWING, 5, 90);  chassis.pid_wait();
  chassis.pid_drive_set(0_in, 127,false);
  chassis.pid_wait();
  intake.move (-127); //scoreTop

  pros::delay (1000);
  chassis.pid_drive_set(50_in, 127,false);
  chassis.pid_wait();
  pros::delay (2000);

}

void skillsBIG(){
  chassis.slew_drive_set(true);  // Enables global slew
  chassis.slew_drive_constants_set(3_in, 60);
  chassis.slew_turn_set(true);  // Enables global slew
  chassis.slew_turn_constants_set(3_deg, 60);
  //Initialize as 270
  chassis.drive_angle_set(270_deg); 
  
  chassis.pid_swing_set(ez::LEFT_SWING, -35, 110); 
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(2_deg, 127);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(13_in, 127);
  chassis.pid_wait_quick();
  intake.move(127);

  loader.set(true);  
  pros::delay(500);

  chassis.pid_drive_set(13_in, 127);
  chassis.pid_wait_quick();

 chassis.pid_drive_set(-2_in, 127,false);
  chassis.pid_wait();
  //Turn 135 left 
  chassis.pid_turn_set(225_deg, 127, false);
  chassis.pid_wait();
  //Back 15 inches
  chassis.pid_drive_set(-14.75_in, 127);
  chassis.pid_wait();
  intake.move(0);


  intake.move(127);
  scorer.move(-127);
  loader.set(false);  
  pros::delay(2000);

  // long goal
intake.move(0);
  scorer.move(0);
   chassis.pid_drive_set(48.25_in, 90);
  chassis.pid_wait();
  loader.set(true);  
  pros::delay(250);
  chassis.pid_turn_set(180_deg, 127, false);
  chassis.pid_wait();

  chassis.pid_drive_set(9_in, 80);
  chassis.pid_wait();

  intake.move(100);
  pros::delay(4000);


  chassis.pid_turn_set(180_deg, 80); // Safety Turn
  chassis.pid_wait();
    intake.move(127);

  chassis.pid_drive_set(-23_in, 127);
  chassis.pid_wait(); 
    intake.move(127);

 chassis.pid_turn_set(180_deg, 127, false);
  chassis.pid_wait();
  loader.set(false);  
  // TUNE END ***************************************
//long goal
  scorer.move(127);
  pros::delay(6000);

   chassis.pid_drive_set(15.5_in, 63.5);
  chassis.pid_wait();

  chassis.pid_turn_set(90_deg, 45);
  chassis.pid_wait();

  //scraper.set (false); might help with getting all blocks
  //pros::delay (1000);

  //conveyor.move (0);

  //drive to other side
  //chassis.pid_turn_relative_set(180, 60);
  //chassis.pid_turn_set(270_deg, 60);
  //chassis.pid_wait();
  chassis.pid_drive_set(92.5_in, 50);
  chassis.pid_wait();

  //drive to long goal
  chassis.pid_turn_set(0, 60);
  chassis.pid_wait();
 chassis.pid_drive_set(7_in, 63.5); //going to match loader 2 pt2; og 22 -2/12
  chassis.pid_wait();

  pros::delay (4000);
  chassis.pid_drive_set(-23_in, 50); //og -18 -2/12
  chassis.pid_wait();

   loader.set (false);
  pros::delay (1000);
  intake.move (0); //stopAll
  scorer.move (0); //stopAll
  pros::delay (500);


  // chassis.drive_angle_set(-90_deg); 
  // chassis.pid_drive_set(8_in, 63.5);
  // chassis.pid_wait();
  // chassis.pid_turn_set(45_deg, 60);
  // chassis.pid_drive_set(25_in, 63.5);
  // chassis.pid_wait();
  // chassis.pid_swing_set(ez::RIGHT_SWING, 5, 90);  chassis.pid_wait();
  // chassis.pid_drive_set(0_in, 127,false);
  // chassis.pid_wait();
  // intake.move (-127); //scoreTop

  // pros::delay (1000);
  // chassis.pid_drive_set(50_in, 127,false);
  // chassis.pid_wait();

}
// Skills
void skills2(){

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