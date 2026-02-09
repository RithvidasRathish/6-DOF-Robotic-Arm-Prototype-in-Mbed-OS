// MultiStepper.pde
// -*- mode: C++ -*-
// Use MultiStepper class to manage multiple steppers and make them all move to 
// the same position at the same time for linear 2d (or 3d) motion.
 
#include <AccelStepper.h>
#include <MultiStepper.h>
#include "Servo.h"



 
// EG X-Y position bed driven by 2 steppers
// Alas its not possible to build an array of these with different pins for each :-(
AccelStepper stepper1(AccelStepper::DRIVER, D2,D3 );
AccelStepper stepper2(AccelStepper::DRIVER, D4,D5 );
AccelStepper stepper3(AccelStepper::DRIVER, D6,D7 );
Servo myservo(D8);

 
// Up to 10 steppers can be handled as a group by MultiStepper
MultiStepper steppers;
 
Timer t;

int main() 
{
  t.start();


  //myservo.write(0);
  // Configure each stepper
  stepper1.setMaxSpeed(100);
  stepper2.setMaxSpeed(100);
  stepper3.setMaxSpeed(100);

  stepper1.setMinPulseWidth(40);
  stepper2.setMinPulseWidth(40);
  stepper3.setMinPulseWidth(40);

 
  // Then give them to MultiStepper to manage
  steppers.addStepper(stepper1);
  steppers.addStepper(stepper2);
  steppers.addStepper(stepper3);
  float a=4.5;
  

  long positions[3]; // Array of desired stepper positions
  
  positions[0] = 3000/a;
  positions[1] = -4600/a;
  positions[2] = 1600/a;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition(); // Blocks until all are in position
  wait(5);
//   for(float p=0; p<1.0; p += 0.1) {
//         myservo = p;
//         wait(0.2);}
  
  positions[0] = 0;
  positions[1] = 0;
  positions[2] = 0;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition(); // Blocks until all are in position
  wait(5);

  positions[0] = -2000/a;
  positions[1] = -4600/a;
  positions[2] = 1600/a;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition(); // Blocks until all are in position
  wait(5);

  positions[0] = 0;
  positions[1] = 0;
  positions[2] = 0;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition(); // Blocks until all are in position
  wait(5);
//   for(float p=0; p<1.0; p += 0.1) {
//         myservo = p;
//         wait(0.2);}
  }
  
//   // Move to a different coordinate
//   positions[0] = -100;
//   positions[1] = 100;
//   steppers.moveTo(positions);
//   steppers.runSpeedToPosition(); // Blocks until all are in position
//   wait(1000);}