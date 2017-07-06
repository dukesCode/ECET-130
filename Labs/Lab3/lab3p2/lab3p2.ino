/* Lab3p2
 *
 * Jean-Luc Major
 * ECET 130-2, Fall 2016
 *
 * This program will ask the user for a single Hex number,
 * then display that character using the 4 LED's interpreted
 * as binary bits.
 */
 
// This will define pins with LED's d1, d2, d3, d4
#define d3 7
#define d2 6
#define d1 5
#define d0 4

void setup() {
   // This sets LED pins as outputs.
   pinMode(d0, OUTPUT);
   pinMode(d1, OUTPUT);
   pinMode(d2, OUTPUT);
   pinMode(d3, OUTPUT);
   // Ensures LED's are off with startup.
   digitalWrite(d0, HIGH);
   digitalWrite(d1, HIGH);
   digitalWrite(d2, HIGH);
   digitalWrite(d3, HIGH);

   Serial.begin(9600);  // Begins serial protocol at 9600 baud
}

void loop() {
  char hex; // input will be stored as char
  Serial.printf("Enter a single HEX character: ");
  while (Serial.available() == 0);
  hex = Serial.read(); // reads serial input as single charl
  Serial.printf("%c\n", hex);

  switch (hex){   // defines which LED's will activate
    case '0': // 0000
      digitalWrite(d0, HIGH);
      digitalWrite(d1, HIGH);
      digitalWrite(d2, HIGH);
      digitalWrite(d3, HIGH);
      break;

    case '1': // 0001
      digitalWrite(d0, LOW);
      digitalWrite(d1, HIGH);
      digitalWrite(d2, HIGH);
      digitalWrite(d3, HIGH);
      break;

    case '2': // 0010
      digitalWrite(d0, HIGH);
      digitalWrite(d1, LOW);
      digitalWrite(d2, HIGH);
      digitalWrite(d3, HIGH);
      break;

    case '3': // 0011
      digitalWrite(d0, LOW);
      digitalWrite(d1, LOW);
      digitalWrite(d2, HIGH);
      digitalWrite(d3, HIGH);
      break;

    case '4': // 0100
      digitalWrite(d0, HIGH);
      digitalWrite(d1, HIGH);
      digitalWrite(d2, LOW);
      digitalWrite(d3, HIGH);
      break;

    case '5': // 0101
      digitalWrite(d0, LOW);
      digitalWrite(d1, HIGH);
      digitalWrite(d2, LOW);
      digitalWrite(d3, HIGH);
      break;

    case '6': // 0110
      digitalWrite(d0, HIGH);
      digitalWrite(d1, LOW);
      digitalWrite(d2, LOW);
      digitalWrite(d3, HIGH);
      break;

    case '7': // 0111
      digitalWrite(d0, LOW);
      digitalWrite(d1, LOW);
      digitalWrite(d2, LOW);
      digitalWrite(d3, HIGH);
      break;

    case '8': // 1000
      digitalWrite(d0, HIGH);
      digitalWrite(d1, HIGH);
      digitalWrite(d2, HIGH);
      digitalWrite(d3, LOW);
      break;

    case '9': // 1001
      digitalWrite(d0, LOW);
      digitalWrite(d1, HIGH);
      digitalWrite(d2, HIGH);
      digitalWrite(d3, LOW);
      break;

    case 'a': // 1010
    case 'A':
      digitalWrite(d0, HIGH);
      digitalWrite(d1, LOW);
      digitalWrite(d2, HIGH);
      digitalWrite(d3, LOW);
      break;

    case 'b': // 1011
    case 'B':
      digitalWrite(d0, LOW);
      digitalWrite(d1, LOW);
      digitalWrite(d2, HIGH);
      digitalWrite(d3, LOW);
      break;

    case 'c': // 1100
    case 'C':
      digitalWrite(d0, HIGH);
      digitalWrite(d1, HIGH);
      digitalWrite(d2, LOW);
      digitalWrite(d3, LOW);
      break;

    case 'd': // 1101
    case 'D':
      digitalWrite(d0, LOW);
      digitalWrite(d1, HIGH);
      digitalWrite(d2, LOW);
      digitalWrite(d3, LOW);
      break;

    case 'e': // 1110
    case 'E':
      digitalWrite(d0, HIGH);
      digitalWrite(d1, LOW);
      digitalWrite(d2, LOW);
      digitalWrite(d3, LOW);
      break;

    case 'f': // 1111
    case 'F':
      digitalWrite(d0, LOW);
      digitalWrite(d1, LOW);
      digitalWrite(d2, LOW);
      digitalWrite(d3, LOW);
      break;

    default:
      Serial.printf("\"INVALID RESPONSE\" , Please try again.\n");
      break;
    }
}
