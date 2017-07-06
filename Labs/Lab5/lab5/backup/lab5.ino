/* Lab5
 *
 * Jean-Luc Major
 * ECET 130-2, Fall 2016
 *
 * This program will write to a 4-digit seven segment display, incrementing
 * the number printed by 1 if a button is pressed once, and will continue
 * incrementing if the button is held.
 *
 * The display will refresh at 60Hz, allowing smooth incrementations of the
 * numbers and minimal ghosting.
 *
 * The display model used in this lab is the Lite-On-LTC-4727JR
 */
 // defines pins on Uno to corresponding 7-seg pins
 #define digit1 2
 #define digit2 3
 #define digit3 4
 #define digit4 5
 #define highA  6
 #define highB  7
 #define highC  8
 #define highD  9
 #define highE  10
 #define highF  11
 #define highG  12
 #define highDP 13

void segWrite();
void numberPrinter(int value);

int display1, display2, display3, display4;
unsigned long previousTime;
int displayInt = 20;

void setup() {
  display1 = display2 = display3 = display4 = 0; // initiates display ints at 0
  // Serial.begin(9600); // Start Serial at 9600BAUD
  pinMode(A0, INPUT);
  pinMode(highA, OUTPUT);
  pinMode(highB, OUTPUT);
  pinMode(highC, OUTPUT);
  pinMode(highD, OUTPUT);
  pinMode(highE, OUTPUT);
  pinMode(highF, OUTPUT);
  pinMode(highG, OUTPUT);
}

void loop() {
  while(digitalRead(A0) == LOW){ //when the button is pressed
    display1++;
    if (display1 > 9) {
      display1 = 0;
      display2++;
    }
    if (display2 > 9) {
      display2 = 0;
      display3++;
    }
    if (display3 > 9) {
      display3 = 0;
      display4++;
    }
    if (display4 > 9){
      display1 = display2 = display3 = display4 = 0;
    }
  }
  segmentDriver();
}

void segmentDriver(){
  digitalWrite(digit1, 1);
  numberPrinter(display1);
  digitalWrite(digit1, 0);

  digitalWrite(digit2, 1);
  numberPrinter(display2);
  digitalWrite(digit2, 0);

  digitalWrite(digit3, 1);
  numberPrinter(display3);
  digitalWrite(digit3, 0);

  digitalWrite(digit4, 1);
  numberPrinter(display4);
  digitalWrite(digit4, 0);
}

void numberPrinter(int value){
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
    digitalWrite(highA, number[value][0]);
    digitalWrite(highB, number[value][1]);
    digitalWrite(highC, number[value][2]);
    digitalWrite(highD, number[value][3]);
    digitalWrite(highE, number[value][4]);
    digitalWrite(highF, number[value][5]);
    digitalWrite(highG, number[value][6]);
}
