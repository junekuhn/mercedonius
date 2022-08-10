
/*
 Stepper Motor Control - speed control

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.
 A potentiometer is connected to analog input 0.

 The motor will rotate in a clockwise direction. The higher the potentiometer value,
 the faster the motor speed. Because setSpeed() sets the delay between steps,
 you may notice the motor is less responsive to changes in the sensor value at
 low speeds.

 Created 30 Nov. 2009
 Modified 28 Oct 2010
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor
int motorSpeed = 50;

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

int stepCount = 0;  // number of steps the motor has taken

void setup() {
  // nothing to do inside the setup
  Serial.begin(9600);
}

void loop() {

  if(Serial.available()) {
    motorSpeed = Serial.read();
    Serial.println(motorSpeed);

  }

      if(motorSpeed >0 && motorSpeed < 100) {
      myStepper.setSpeed(motorSpeed);
    }
//  myStepper.setSpeed(20);
  myStepper.step(stepsPerRevolution/100);

}
