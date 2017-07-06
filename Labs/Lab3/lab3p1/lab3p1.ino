/* Lab3p1
 *
 * Jean-Luc Major
 * ECET 130-2, Fall 2016
 *
 * This program will take input (Miles) and multiply it
 * and output a number (kilometers)
 */
// This will define pins with LED's d1, d2, d3, d4
#define d1 7
#define d2 6
#define d3 5
#define d4 4

void setup() {
   // This sets LED pins as outputs.
   pinMode(d1, OUTPUT);
   pinMode(d2, OUTPUT);
   pinMode(d3, OUTPUT);
   pinMode(d4, OUTPUT);
   // Ensures LED's are off with startup.
   digitalWrite(d1, HIGH);
   digitalWrite(d2, HIGH);
   digitalWrite(d3, HIGH);
   digitalWrite(d4, HIGH);

   Serial.begin(9600);  // Begins serial protocol at 9600 baud
   // This is a banner
   Serial.printf("** Mile to Kilometer Conversion **\n");
   Serial.printf("==================================\n");
 }

 void loop() {
   float miles, kiloM;
   Serial.printf("Please enter a distance in miles.\n");
   Serial.printf("This number may be floating point.\n");
   Serial.printf("Miles? =>  \t");

   while (Serial.available() == 0); // Waits for input
   miles = Serial.parseFloat();     // Grabs user input
   kiloM = miles*1.609;             // 1.609 km/Mile
   Serial.printf("You've entered %.1f miles.\nThat is %.2f kilometers.\n\n\n", miles, kiloM);
}
