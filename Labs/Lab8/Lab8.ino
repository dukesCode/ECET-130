/*  Lab 8 - Stepper Motors
 *
 *  Jean-Luc Major
 *  ECET-130-02, Fall 2016
 *
 *  This motor has 48 steps
 *  Brown to Black: inductor 1
 *    Red is common connector
 *  Yellow to orange: inductor 2
 *    Red is common connector
 *  Resistances:
 *    Black == Ground 1
 *    Brown-Black: 157.4 ohms
 *    Red1-Black: 80.6 ohms
 *
 *    Yellow == Ground 2
 *    Red-Yellow: 78.8 ohms
 *    Orange-Yellow: 156 ohms
 */
#include <Stepper.h>

#define potPin A1
#define button0 A0
#define button1 A2

Stepper stepper(48,8,9,10,11);

void setup() {
  stepper.setSpeed(20);
  Serial.begin(9600);
  digitalWrite(7, 1);
}

void loop() {
  int potReading = map(analogRead(potPin), 0, 1023, 100, 0);
  // maps pot value to a value to control the speed
  int powerButton = digitalRead(button0);
  int optButton = digitalRead(button1);

  if (powerButton == 0 && optButton == 0){

  }
  if (powerButton == 1 && optButton == 0){  // when power button pressed
    stepper.step(10);

  }
  if (powerButton == 1 && optButton == 1){ // when power and option button pressed
    stepper.step(48);
  }
  Serial.printf("%i %i %i\n", potReading, powerButton, optButton);
}

void CW(int speed){

}

void CCW(int speed){

}
