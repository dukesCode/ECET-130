/*  Lab 9 - RGB CA LED
 *
 *  Jean-Luc Major
 *  ECET-130-02, Fall 2016
 *
 * Was not able to get Fade function to function correctly
 */
#define pinR 9
#define pinG 10
#define pinB 11

typedef struct {
  unsigned char r;
  unsigned char g;
  unsigned char b;
} rgb;

//Prototypes
char getInput();              // ask for character on serial monitor

void displayLed(rgb *colour); // display current colour

// smoothly transition from fadeFrom LED to fadeTo LED over fadeTime seconds
//void fadeLed(rgb fadeFrom, rgb fadeTo, int fadeTime);

void randomLed(int duration);

void programBanner();

void setup(){
  Serial.begin(9600); // begins serial at 9600 BAUD
  Serial.flush();     // empties serial buffer
  randomSeed(analogRead(0));
  programBanner();
}

void loop(){
  // defines needed colour values
  rgb black = {0, 0, 0};
  rgb brown = {51, 25, 0};
  rgb red = {255, 0, 0};
  rgb orange = {255, 128, 0};
  rgb yellow = {255, 255, 0};
  rgb green = {0, 255, 0};
  rgb blue = {0, 0, 255};
  rgb violet = {255, 0, 255};
  rgb grey = {56, 56, 56};
  rgb white = {255, 255, 255};

  char fadeT, fadeF;
  int randomTime = random(2000, 5000);
  char userIn = getInput();

  // Serial.printf("%c ", userIn);
  switch (userIn){
    case '0':
      displayLed(&black);
      break;
    case '1':
      displayLed(&brown);
      break;
    case '2':
      displayLed(&red);
      break;
    case '3':
      displayLed(&orange);
      break;
    case '4':
      displayLed(&yellow);
      break;
    case '5':
      displayLed(&green);
      break;
    case '6':
      displayLed(&blue);
      break;
    case '7':
      displayLed(&violet);
      break;
    case '8':
      displayLed(&grey);
      break;
    case '9':
      displayLed(&white);
      break;
    case 'r':
    case 'R':
      randomLed(randomTime);
      break;
    case 'f':
    case 'F':
      Serial.print("\nEnter 2 RGB values");
      fadeF = getInput();
      fadeT = getInput();

  }
}

void displayLed(rgb *colour){
  // points to value in struct then subtracts value by 255 due to common cathode logic
  analogWrite(pinR, 255-colour->r);
  analogWrite(pinG, 255-colour->g);
  analogWrite(pinB, 255-colour->b);
}
char getInput(){
  char userIn;

  while (Serial.available() == 0);  // waits for input
  userIn = Serial.read(); // fetches user input character

  return userIn;
}

// void fadeLed(rgb fadeFrom, rgb fadeTo, int fadeTime){
//
// }

void randomLed(int duration){
  // writes random value between 0 and 255 to r g and b prints
  analogWrite(pinR, random(0,255));
  analogWrite(pinG, random(0,255));
  analogWrite(pinB, random(0,255));

  delay(duration);  // delays duration milliseconds
  analogWrite(pinR, 255); // turns off R pin
  analogWrite(pinG, 255); // turns off G pin
  analogWrite(pinB, 255); // turns off B pin
}
void programBanner(){
  Serial.print("\n========================================================================");
  Serial.print("\n========================================================================\n\n");
  Serial.print("   /$$$$$$$   /$$$$$$  /$$$$$$$        /$$       /$$$$$$$$ /$$$$$$$   \n");
  Serial.print("  | $$__  $$ /$$__  $$| $$__  $$      | $$      | $$_____/| $$__  $$  \n");
  Serial.print("  | $$  \\ $$| $$  \\__/| $$  \\ $$      | $$      | $$      | $$  \\ $$  \n");
  Serial.print("  | $$$$$$$/| $$ /$$$$| $$$$$$$       | $$      | $$$$$   | $$  | $$  \n");
  Serial.print("  | $$__  $$| $$|_  $$| $$__  $$      | $$      | $$__/   | $$  | $$  \n");
  Serial.print("  | $$  \\ $$| $$  \\ $$| $$  \\ $$      | $$      | $$      | $$  | $$ \n");
  Serial.print("  | $$  | $$|  $$$$$$/| $$$$$$$/      | $$$$$$$$| $$$$$$$$| $$$$$$$/  \n");
  Serial.print("  |__/  |__/ \\______/ |_______/       |________/|________/|_______/  \n\n");
  Serial.print("\n========================================================================");
  Serial.print("\n========================================================================\n\n");
  Serial.print("\n0-9 will give you a resistor colour value");
  Serial.print("\nf or F will fade colours for 2-5 seconds");
  Serial.print("\nr or R will display random colours for 2-5 seconds\n");
  Serial.print("\nPlease chose an option... ");
}
