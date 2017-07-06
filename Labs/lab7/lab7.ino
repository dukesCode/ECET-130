/* Lab 7 - HC-SR04 Ultrasonics Transducer
 *
 * Jean-Luc Major
 * ECET 130-2, Fall 2016
 *
 * This program will obtain a reading from the attached ultrasonic transducer
 * then display the results as a bar graph.
 */

 #include <LiquidCrystal.h>

 #define trigger 6  // defines trigger as pin 6
 #define echo 7     // defines echo to pin 7

 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 // creates LiquidCrystal object lcd on these pins

 void setup( ) {
   pinMode(trigger, OUTPUT);  // sets trigger as OUTPUT
   digitalWrite(trigger, LOW); // ensures trigger is LOW when program starts
   lcd.begin(16, 2); // Starts LCD and sets 16 characters characters and 2 lines
   Serial.begin(9600); // starts serial for debugging
 }

 void loop() {
   unsigned long pulseWidth;
   float cm;

   pulseWidth = pulse();      // will generate pulseWidth value

   delay(60);                 // delays next pulse by aprox 60 ms

   cm = distance(pulseWidth); // converts the pulseWidth to cm

   lcdPrint(cm);      // feeds the pointer for the bar array and dist
                              // to the LCD graphing function
 }

 void lcdPrint(float dist){
   lcd.setCursor(0,0);
   lcd.printf("distance: %3.0f", dist);
   lcd.setCursor(0,1);
   bars(dist);
 }

 void bars(float dist){
   const int maxStars = 16;
   char bar[maxStars+1];
   // sets array of chars to 17 units, were last unit will be null character
   int barInt = map(dist, 200, 4, 0, 16);
   // map the distance of barInt from 200 to 4 for granularity

   for (int incr = 0; incr < barInt+1; incr++){
     bar[incr] = '*'; // assigns character * to each element in range
   }
   for (int incr = barInt+1; incr < maxStars; incr++){
     bar[incr] = ' '; // assigns space char to each element in range
   }

   bar[maxStars] = '\0'; // lest last element in array as null character
   lcd.printf("%s", bar); //prints to LCD
 }

 float distance(unsigned long pulse){
   float cm;
   cm = pulse / 58; // divide pulse by 58 due to formula uS/58cm
   while (cm > 400){   // will return 0 if outside of spec operating distance
     cm = 0;
   }
   return cm;
 }

 unsigned long pulse(){
   unsigned long t1;
   unsigned long t2;
   unsigned long pulseWidth;

   digitalWrite(trigger, HIGH); // will generate wave
   delayMicroseconds(10);       // will delay 10 uS
   digitalWrite(trigger, LOW);  // will set trigger LOW

   while (digitalRead(echo) == 0); // waits while echo low

   t1 = micros();
   while (digitalRead(echo) == 1); // when echo high (triggered)
   t2 = micros();
   pulseWidth = t2 - t1; // compares the two times

   return pulseWidth;
 }
