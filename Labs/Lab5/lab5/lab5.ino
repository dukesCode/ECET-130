/* Lab5
 *
 * Jean-Luc Major
 * ECET 130-2, Fall 2016
 *
 * This program will write to a 4-digit seven segment display, incrementing
 * the number printed by 1 if a button is pressed once, and will continue
 * incrementing if the button is held.
 *
 * The button is wired to pin A0. LED segments are wired to pins 6 to 13
 *
 * The display will refresh at a rate allowing smooth incrementations of the
 * numbers and minimal ghosting.
 *
 * The display model used in this lab is the Lite-On-LTC-4727JR
 *
 * Button debounce is from Arduino Wiki, code writen by David A. Mellis
 * https://www.arduino.cc/en/Tutorial/Debounce
 *
 *  Pin 2, 3, 4, 5 are attached to transistors
 *
 *  LED Segment Pins:
 *  A(6) B(7) C(8)  D(9)  E(10) F(11) G(12) DP(13)
 */

 int d1, d2, d3, d4; // int value for each 7-seg digit

 int buttonState;    // will store button current state
 int lastButtonState = HIGH; // stores buttons previous state, defaults HIGH

 boolean twoSecondRule; // true if button held for less than desired time
 boolean moreSeconds;   //  true if button held for less than desired time
 unsigned long buttonTime; // stores button time when b held > 2s

 unsigned long lastDebounce;        // last time the button was pressed
 unsigned long debounceDelay = 50;  // debounce time. Modified if needed

 unsigned long digitTimer = 4; // time to switch between each 7-seg

 void setup(){
   d1 = d2 = d3 = d4 = 0; // sets value for 4 7-seg displays to 0
   for (int ledPin = 2; ledPin < 14; ledPin++){ // assigns pins 2 to 13 as OUTPUT
     pinMode(ledPin, OUTPUT);
   }
   digitalWrite(13, LOW); // sets pin 13 as LOW as it is not needed
   pinMode(A0, INPUT); // assigns analog pin A0 to read as digital pin
 }

 void loop() {
   int buttonRead = digitalRead(A0); // Sets button read to current button state
   if (buttonRead == 1){ // when button reads high, twoSecondRule will be false
    twoSecondRule = false;
  }

  // controls debounce
   if (buttonRead != lastButtonState) {
     lastDebounce = millis(); //resets debounce timer
   }
   // controls debounce
   if ((millis() - lastDebounce) > debounceDelay) {
     if (buttonRead != buttonState){
       buttonState = buttonRead;
     }
     // button press passed debouce tests
     if (buttonState == 0){

// when the button in pressed less than a half second, d1 will only increment by 1
      if ((millis() - lastDebounce) < 500 && twoSecondRule == false){
        twoSecondRule = true;
        incrementing();
      }
// when the button is held for longer than the half second, d1 will increment by 1
// every 10 milliseconds
      if ((millis() - lastDebounce) > 500 && moreSeconds == false){
        buttonTime = millis();
        moreSeconds = true;
        incrementing();
      }
      // when buttonTime is greater than 10ms, sets moreSeconds boolean to false
      // allowing above if statement to be true
      if ((millis() - buttonTime) > 10 ){
        moreSeconds = false;
      }
     }
   }
   lastButtonState = buttonRead;

   // will control which 7-segment is being writen to
   sevenSeg(d1, 2);
   delay(digitTimer);
   sevenSeg(d2, 3);
   delay(digitTimer);
   sevenSeg(d3, 4);
   delay(digitTimer);
   sevenSeg(d4, 5);
   delay(digitTimer);
 }

// increments the value of d1 and will roll over to the next digit when greater
// than 9
 void incrementing(){
   d1++;
   if (d1 > 9){ // rollover to 10's
     d1 = 0;
     d2++;
     if (d2 > 9){ // rollover to 100's
       d2 = 0;
       d3++;
       if (d3 > 9){ // rollover to 1000's
         d3 = 0;
         d4++;
         if (d4 > 9){ // resets counters to 0 when greater than 9999
           d1 = d2 = d3 = d4 = 0;
         }
       }
     }
   }
 }

 // controls which 7-seg is activated and what number is being displayed
 // inputs value and which 7-segment as ints
 void sevenSeg(int value, int digit){

   // stores 7-segment data in 2D array.
   // LED's arranged in order a, b, c, d, e, f, g
   char number[10][7] = {
     {1,1,1,1,1,1,0}, // 0
     {0,1,1,0,0,0,0}, // 1
     {1,1,0,1,1,0,1}, // 2
     {1,1,1,1,0,0,1}, // 3
     {0,1,1,0,0,1,1}, // 4
     {1,0,1,1,0,1,1}, // 5
     {1,0,1,1,1,1,1}, // 6
     {1,1,1,0,0,0,0}, // 7
     {1,1,1,1,1,1,1}, // 8
     {1,1,1,0,0,1,1}, // 9
   };

   // sets each 7-seg to low (OFF)
    for (int ledCount = 2; ledCount < 6; ledCount++){
      digitalWrite(ledCount, 0);
      //delay(1);
    }

    // sets appropriate segment to high or low. Uses char number as reference
    for (int ledPin = 0; ledPin < 7; ledPin++){
      digitalWrite((ledPin + 6), number[value][ledPin]);

      // sets desired 7-segment high (ON)
      digitalWrite(digit, 1);

    }
 }
