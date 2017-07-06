/* Lab 6-B - Pots and Servos
 *
 * Jean-Luc Major
 * ECET 130-2, Fall 2016
 *
 * This program will read the resistance from a pot and move the servo arm to
 * corresponding angle. Counter-clockwise for low pot reading, clockwise for high.
 */
#include <Servo.h>  // includes appropriate servo library

// Defines Analog pins for pot and servo
#define potPin A1
#define servoPin A2

Servo servo;  // creates servo called "servo"

int potInput = 0;   // Interger for storing pot value
int servoOut = 0;   // Interger for storing servo output

void setup() {
  servo.attach(servoPin); // Attaches servoPin to  the servo object
  Serial.begin(9600);     // Begins serial at 9600 BAUD
}

void loop() {
  potInput = analogRead(potPin);  // assigns potPin value to potInput
  servoOut = map(potInput, 0, 1023, 0, 180); // Maps potInput values to servoOut
  Serial.printf("%i\n",servoOut);

  servo.write(servoOut); // writes to servo object
  delay(15);
}
