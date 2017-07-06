/* Lab 6-C - Pots and Servos
 *
 * Jean-Luc Major
 * ECET 130-2, Fall 2016
 *
 * This program will read the resistance from a pot and store the reading in an
 * array of 8 spaces. The array will then be summed and then an average will be
 * obtained. The average will then print to serial.
 * A servo arm will move corresponding to the average of the pot.
 */
#include <Servo.h>  // includes appropriate servo library

// Defines Analog pins for pot and servo
#define potPin A1
#define servoPin A2

Servo servo;  // creates servo called "servo"

int potInput[8];
  // array to store pot values

int loopCount = 0;
  // counts loop

int servoOut;
 // int to store the adjusted average potInput

void setup() {
  servo.attach(servoPin); // Attaches servoPin to  the servo object
  Serial.begin(9600);     // Begins serial at 9600 BAUD
}

void loop() {
  int potAv = 0; // int to store the average of potInput array
  potInput[loopCount] = analogRead(potPin);

  for (int counter = 0; counter < 8; counter++){
    potAv = potAv + potInput[counter]; // sums all the array ints
  }
  potAv = (potAv/8); // divides the sum by 8 to obtain average

  loopCount++;
  if (loopCount >= 8 ){ // if count is greater than 7, count will reset
    loopCount = 0;
    Serial.printf("%i\n", potAv); // prints potAv to serial
    servoOut = map(potAv, 0, 1023, 0, 180); // maps potAv to int servoOut

    servo.write(servoOut); // writes to servo object
    delay(15);
  }
}
