/* Lab4p1
 *
 * Jean-Luc Major
 * ECET 130-2, Fall 2016
 *
 * This program will take a input (resistorInt)
 * and extract the two leading digits and a modifyer
 * value. It will then convert the three values to the
 * appropriate colour bands.
 */
void colour();  // initializes function

void setup() {
  Serial.begin(9600); //starts serial at 9600 BAUD
}

void loop() {
  unsigned long resistorInt;
  // Set as unsigned long to allow rediculously large + value
  int firstColour, secondColour, thirdColour = 0;
  // variables for each colourband
  Serial.printf("Enter a resistor value in Ohm's: \n");
  while(Serial.available() == 0); //waits for input
  resistorInt = Serial.parseInt();  // Grabs long int from serial
  Serial.printf("%lu Ohms:\t",resistorInt);
  if (resistorInt < 10) { // if resistor under 10 Ohms
    firstColour = resistorInt;
    secondColour = thirdColour = 0;
  } else if (resistorInt < 100) { // if resistor under 100
    secondColour = resistorInt % 10;
    firstColour = resistorInt / 10;
    thirdColour = 0;
  } else {
    while (resistorInt >= 100){ // resistor 100 Ohm and beyond
      resistorInt = resistorInt / 10;
      thirdColour++;
    }
    secondColour = resistorInt % 10;
    firstColour = resistorInt / 10;
  }
  // Sends value to colour function
  colour(firstColour);
  colour(secondColour);
  colour(thirdColour);
  Serial.printf("\n");
}

// Function will take int value and print corresponding colour band
void colour(int colourInt){
  switch (colourInt){
    case 0:
      Serial.printf("Blk\t");
      break;
    case 1:
      Serial.printf("Brn\t");
      break;
    case 2:
      Serial.printf("R\t");
      break;
    case 3:
      Serial.printf("O\t");
      break;
    case 4:
      Serial.printf("Y\t");
      break;
    case 5:
      Serial.printf("Grn\t");
      break;
    case 6:
      Serial.printf("Blu\t");
      break;
    case 7:
      Serial.printf("V\t");
      break;
    case 8:
      Serial.printf("Gry\t");
      break;
    case 9:
      Serial.printf("W\t");
      break;
    default:
      Serial.printf("Invalid number");
      break;
  }
}
