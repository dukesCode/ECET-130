/* Lab2p3
 *
 * Jean-Luc Major
 * ECET 130-2, Fall 2016
 *
 * This program will add functionality to last weeks lab.
 * Pin 2 will read a LOW signal when the switch is activated.
 * While pin 2 is activated, lights will flash from left to
 * right at 200m/s. While switch inactive (not pressed), lights
 * will flash from right to left.
 * This program will write to serial and indicate how many times
 * it has completed leftToRight or rightToLeft
 */

 // Pin 7 wired to Green LED, Pin 6 to Red, and 5 to Yellow
 int ledGreen = 7;
 int ledYellow = 6;
 int ledRed = 5;

 int lToR = 0, rToL = 0;  // Creates int for Serial to print

// setup will run once
void setup() {
  Serial.begin(9600);   // Starts serial with 9600 baud rate

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
  while (digitalRead(2)== LOW){    // Switch pressed. Lights leftToRight
    digitalWrite(ledGreen, LOW);   // turn Green on unsing high volt
    delay(200);                    // wait 1/5 second
    digitalWrite(ledGreen, HIGH);  // turn Green off

    digitalWrite(ledYellow,LOW);   // yellow on
    delay(200);                    // wait 1/5 second
    digitalWrite(ledYellow, HIGH); // yellow off

    digitalWrite(ledRed, LOW);     // red on
    delay(200);                    // wait 1/5 second
    digitalWrite(ledRed, HIGH);    // red off

    lToR++;
    Serial.printf("leftToRight: %i \t", lToR);
    Serial.printf("rightToLeft: %i \n", rToL);
  }
  while (digitalRead(2)== HIGH){   // Switch not pressed. Lights rightToLeft
    digitalWrite(ledRed, LOW);     // turn Red on unsing high volt
    delay(200);                    // wait 1/5 second
    digitalWrite(ledRed, HIGH);    // turn Red off

    digitalWrite(ledYellow,LOW);   // yellow on
    delay(200);                    // wait 1/5 second
    digitalWrite(ledYellow, HIGH); // yellow off

    digitalWrite(ledGreen, LOW);   // green on
    delay(200);                    // wait 1/5 second
    digitalWrite(ledGreen, HIGH);  // green off

    rToL++;
    Serial.printf("leftToRight: %i \t", lToR);
    Serial.printf("rightToLeft: %i \n", rToL);
  }
}
