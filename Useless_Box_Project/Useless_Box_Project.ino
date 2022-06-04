/* Useless Box Project
 * by Stepan Nazarov
 * https://susllike.github.io
 */

#include <Servo.h>

Servo lidServo; //Servo object for the lid
Servo armServo; //Servo object for the arm

int switch_pin = 7; //Switch for enabling the box
int pos = 0; //Position variable for movement

void setup() {
  lidServo.attach(9);  //Attaches the servo on pin 9 to the servo object
  lidServo.write(0); //Preventing the attachment movement of the servo
  armServo.attach(10);
  armServo.write(0); //Same thing here
  
  pinMode(switch_pin, INPUT);
}

void loop() {
  if (digitalRead(switch_pin) == 1) {
    teset_behavior(); //Testing code for Soham to debug the box
  }
  /*
  behavior_one();
  reset();
  behavior_two();
  reset();
  behavior_three();
  reset();
  behavior_four();
  reset();
  behavior_five();
  reset();
  */
}

void move_lid(int i_angle, int f_angle) { //i - initial, f - final
  int increment = (i_angle < f_angle) ? 1 : -1;
  for (pos = i_angle; pos <= f_angle; pos += increment) { //Goes from initial position degree to final degree, in either direction dependent on the comparison
    // in steps of 1 degree
    lidServo.write(pos); //Tell servo to go to position in variable 'pos'
    delay(10); //Waits 15 ms for the servo to reach the position
  }
}

void move_arm(int i_angle, int f_angle) {
  int increment = (i_angle < f_angle) ? 1 : -1;
  for (pos = i_angle; pos <= f_angle; pos += increment) {
    // in steps of 1 degree
    armServo.write(pos);
    delay(10);
  }
}

void test_behavior() {
  move_arm(0, 180);
  delay(100);
  move_arm(180, 0);
  delay(100);
}

void behavior_one() {
  move_lid(0, 60); //Opening the lid
  move_arm(0, 180); //Moving the arm to close the switch
  move_arm(180, 0); //Moving the arm back in the box
  move_lid(60, 0); //Closing the box
}

void behavior_two() {
  move_lid(0, 60); //Opening the lid
  delay(3000); //Waiting
  move_arm(0, 180); //Moving the arm to close the switch
  move_arm(180, 0); //Moving the arm back in the box
  move_lid(60, 0); //Closing the box
}

void behavior_three() {
  delay(3000); //Dramatic waiting
  move_lid(0, 30); //Opening the lid halfway
  delay(1000); //More dramatic waiting
  move_lid(30, 60); //Opening the lid fully
  move_arm(0, 180); //Moving the arm to close the switch
  move_arm(180, 0); //Moving the arm back in the box
  move_lid(60, 0); //Closing the box
}

void behavior_four() {
  move_lid(0, 60); //Opening the lid
  move_arm(0, 90);//Moving the arm halfway
  move_arm(90, 135); //Moving the arm 3/4 way
  move_arm(135, 180); //Closing the switch
  move_arm(180, 0); //Moving the arm back in the box
  move_lid(60, 0); //Closing the box
}

void behavior_five() {
  move_lid(0, 60); //Opening the lid
  
  for (int i = 0; i < 2; i++) { //Moving towards closing the switch several times, but not closing
    move_arm(0, 170); //Moving towards the switch
    move_arm(170, 0); //Moving the arm back in the box
  }
  
  move_arm(0, 180); //Closing the switch
  move_arm(180, 0); //Moving the arm back in the box
  move_lid(60, 0); //Closing the box
}
