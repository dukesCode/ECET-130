/* Lab1
 *
 * Jean-Luc Major
 * ECET 130-2, Fall 2016
 *
 * This program will have 3 LED's turn on and off from left to right at a rate of 250mS.
 * LED's are wired using a single 5V line from the Arduino Uno to the 3 Resistors parallel,
 * then to LEDs then to ground.
 */

 // Pin 7 wired to Green LED, Pin 6 to Red, and 5 to Yellow
 int ledGreen = 7;
 int ledYellow = 6;
 int ledRed = 5;

// setup will run once
void setup() {
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);

  // starts the LED's with HIGH, ensureing that they are off when program starts
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledYellow, HIGH);
  digitalWrite(ledRed, HIGH);
}

// the loop routine will run an infinite amount of times
void loop() {
  digitalWrite(ledGreen, LOW);   // turn Green on unsing high volt
  delay(250);                     // wait 1/4 second
  digitalWrite(ledGreen, HIGH);    // turn Green off

  digitalWrite(ledYellow,LOW);      // red on
  delay(250);                     // wait 1/4 second
  digitalWrite(ledYellow, HIGH);      // red off

  digitalWrite(ledRed, LOW);  // yellow on
  delay(250);                     // wait 1/4 second
  digitalWrite(ledRed, HIGH);   // yellow off
}
