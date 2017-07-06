/* Lab2p1
 *
 * Jean-Luc Major
 * ECET 130-2, Fall 2016
 *
 * This program will add functionality to last weeks lab.
 * Pin 2 will read a LOW signal when the switch is activated.
 * This will cause the LED's to turn on in order of left to right
 * at a 200ms rate.
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

  // starts the LED's with HIGH, ensuring that they are off when program starts
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledYellow, HIGH);
  digitalWrite(ledRed, HIGH);
}

// the loop routine will run an infinite amount of times
void loop() {
  while (digitalRead(2)== LOW){       // this line will read pin 2 status.
    digitalWrite(ledGreen, LOW);   // turn Green on unsing high volt
    delay(200);                    // wait 1/5 second
    digitalWrite(ledGreen, HIGH);  // turn Green off

    digitalWrite(ledYellow,LOW);   // yellow on
    delay(200);                    // wait 1/5 second
    digitalWrite(ledYellow, HIGH); // yellow off

    digitalWrite(ledRed, LOW);     // red on
    delay(200);                    // wait 1/5 second
    digitalWrite(ledRed, HIGH);    // red off
  }
}
