/* Lab2p4
 *
 * Jean-Luc Major
 * ECET 130-2, Fall 2016
 *
 * This program will add functionality to last weeks lab.
 * Pin 2 will read a LOW signal when the switch is activated.
 * When the switch is activated, the LED's will shine from
 * left to right 5 times, then from right to left 3 times.
 * A counter keeps track of how many times the lights have
 * flashed in each direction. The program will wait until
 * the button has been pressed before restarting the routine.
 */

 // Pin 7 wired to Green LED, Pin 6 to Red, and 5 to Yellow
 int ledGreen = 7;
 int ledYellow = 6;
 int ledRed = 5;

 int lToR = 0, rToL = 0;// Creates int for Serial to print

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
  while (digitalRead(2)== LOW){    // Switch pressed, sequence starts
    // This loop will have lights flash leftToRight 5 times
    for (int leftCount=0; leftCount<5; leftCount++){
      digitalWrite(ledGreen, LOW);   // turn Green on unsing high volt
      delay(100);                    // wait 1/6 second
      digitalWrite(ledGreen, HIGH);  // turn Green off

      digitalWrite(ledYellow,LOW);   // yellow on
      delay(100);                    // wait 1/6 second
      digitalWrite(ledYellow, HIGH); // yellow off

      digitalWrite(ledRed, LOW);     // red on
      delay(100);                    // wait 1/6 second
      digitalWrite(ledRed, HIGH);    // red off

      lToR++;
      Serial.printf("leftToRight: %i \t rightToLeft: %i \n", lToR, rToL);
    }
    // This loop will have lights flash rightToLeft 3 times
    for (int rightCount=0; rightCount<3; rightCount++){
      digitalWrite(ledRed, LOW);     // red on
      delay(100);                    // wait 1/6 second
      digitalWrite(ledRed, HIGH);    // red off

      digitalWrite(ledYellow,LOW);   // yellow on
      delay(100);                    // wait 1/6 second
      digitalWrite(ledYellow, HIGH); // yellow off

      digitalWrite(ledGreen, LOW);   // turn Green on unsing high volt
      delay(100);                    // wait 1/6 second
      digitalWrite(ledGreen, HIGH);  // turn Green off

      rToL++;
      Serial.printf("leftToRight: %i \t rightToLeft: %i \n", lToR, rToL);
    }
  }
}
