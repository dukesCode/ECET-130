/* Lab4p3
 *
 * Jean-Luc Major
 * ECET 130-2, Fall 2016
 *
 * This program will take a input (resistorInt)
 * and extract the two leading digits and a modifyer
 * value. It will then convert the three values to the
 * appropriate colour bands and print the resulting
 * colours on the attached LCD with 2 rows and 16 columns.
 *
 * This program requires LiquidCrystal Library
 */
#include <LiquidCrystal.h>

void colour();  // initializes function
// initializes LCD on following pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600); //starts serial at 9600 BAUD
  lcd.begin(16, 2); // Starts LCD and sets how many characters and lines
}

void loop() {
  unsigned long resistorInt;
  // Set as unsigned long to allow rediculously large + value
  int firstColour, secondColour, thirdColour = 0;
  // variables for each colourband
  lcd.setCursor(0,0); // sets lcd cursor to column 0 row 1
  Serial.printf("Enter a resistor value in Ohm's: ");
  while(Serial.available() == 0); //waits for input
  resistorInt = Serial.parseInt();  // Grabs long int from serial
  Serial.printf("%lu\n");
  lcd.clear();  // clears LCD for new output
  lcd.printf("Ohms: %lu", resistorInt);
  if (resistorInt < 10) { // if resistor under 10 Ohms
    firstColour = resistorInt;
    secondColour = thirdColour = 0;
  } else if (resistorInt < 100) { // if resistor under 100 Ohms
    secondColour = resistorInt % 10; // extracts second leading value
    firstColour = resistorInt / 10;  // extracts leading value
    thirdColour = 0;
  } else {
    while (resistorInt >= 100){ // finds modifyer value
      resistorInt = resistorInt / 10;
      thirdColour++;
    }
    secondColour = resistorInt % 10;  // extracts second leading value
    firstColour = resistorInt / 10;   // extracts leading value
  }
  lcd.setCursor(0,1); // set cursor to column 0 row 1
  // Sends values to colour function
  colour(firstColour);
  colour(secondColour);
  colour(thirdColour);
}

// Function will take int value and print corresponding colour band
void colour(int colourInt){
  switch (colourInt){
    case 0:
      lcd.print("Blk ");
      break;
    case 1:
      lcd.print("Brn ");
      break;
    case 2:
      lcd.print("R ");
      break;
    case 3:
      lcd.print("O ");
      break;
    case 4:
      lcd.print("Y ");
      break;
    case 5:
      lcd.print("Grn ");
      break;
    case 6:
      lcd.print("Blu ");
      break;
    case 7:
      lcd.print("V ");
      break;
    case 8:
      lcd.print("Gry ");
      break;
    case 9:
      lcd.print("W ");
      break;
  }
}
