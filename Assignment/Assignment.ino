/* Assignement1 - Pointers
 *
 * Jean-Luc Major
 * ECET-130-02, Fall 2016
 *
 * This program will calculate the current in a resistor given the value of
 * the resistor and the voltage across it.
 */

// Prototypes to specifications
void explainProgram(void);
void getValues(float *ohms, float *volts);
float doCalculations(float res, float volt);
void displayAnswer(float amps);

void setup() {
  Serial.begin(9600);  // starts serial @ 9600 BAUD
  Serial.flush();      // Flush buffer of any previous data
  Serial.print("\n");  // new line for formatting
  explainProgram();    // Runs banner generation
}

void loop() {
  float res, amps, volt;
  getValues(&res, &volt);   // passes address for res and volts as arguments
  amps = doCalculations(res, volt); // passes res and volts as arguments

  displayAnswer(amps);
}

void explainProgram(void){
  // Will print a stylized banner
  Serial.print("=====================================================================================================\n");
  Serial.print("=====================================================================================================\n\n");
  Serial.print("    /$$$$$$                     /$$                                                         /$$    \n");
  Serial.print("   /$$__  $$                   |__/                                                        | $$    \n");
  Serial.print("  | $$  \\ $$  /$$$$$$$ /$$$$$$$ /$$  /$$$$$$  /$$$$$$$  /$$$$$$/$$$$   /$$$$$$  /$$$$$$$  /$$$$$$  \n");
  Serial.print("  | $$$$$$$$ /$$_____//$$_____/| $$ /$$__  $$| $$__  $$| $$_  $$_  $$ /$$__  $$| $$__  $$|_  $$_/  \n");
  Serial.print("  | $$__  $$|  $$$$$$|  $$$$$$ | $$| $$  \\ $$| $$  \\ $$| $$ \\ $$ \\ $$| $$$$$$$$| $$  \\ $$  | $$    \n");
  Serial.print("  | $$  | $$ \\____  $$\\____  $$| $$| $$  | $$| $$  | $$| $$ | $$ | $$| $$_____/| $$  | $$  | $$ /$$\n");
  Serial.print("  | $$  | $$ /$$$$$$$//$$$$$$$/| $$|  $$$$$$$| $$  | $$| $$ | $$ | $$|  $$$$$$$| $$  | $$  |  $$$$/\n");
  Serial.print("  |__/  |__/|_______/|_______/ |__/ \\____  $$|__/  |__/|__/ |__/ |__/ \\_______/|__/  |__/   \\___/  \n");
  Serial.print("                                   /$$   \\ $$                                                      \n");
  Serial.print("                                   |  $$$$$$/                                                      \n");
  Serial.print("                                   \\_______/                                                       \n");
  Serial.print("=====================================================================================================\n");
  Serial.print("=====================================================================================================\n\n");
  Serial.print("  - Written by Jean-Luc Major for ECET-130\n\n");
  Serial.print("  - This program will calculate the current through a resistor when given:\n");
  Serial.print("      - Voltage across the resistor, and \n");
  Serial.print("      - The value of the resistor in Ohms\n\n");
  Serial.print("=====================================================================================================\n\n");

}

void getValues(float *ohms, float *volts){
  Serial.printf("Enter a resistor value: ");
  while (Serial.available() == 0); // waits for user input
  *ohms = Serial.parseFloat();       // grabs float from serial buffer
  Serial.printf("%.2f Ohms\n", *ohms);      // prints resistor value

  Serial.printf("Enter a voltage value: ");
  while (Serial.available() == 0); // waits for user input
  *volts = Serial.parseFloat();      // grabs float from serial buffer
  Serial.printf("%.2f Volts\n", *volts);     // prints volt value
}

float doCalculations(float res, float volt){
  float amps;
  amps = (volt / res); // Ohm's Law V = I*R
  return amps;
}

void displayAnswer(float amps){
  Serial.printf("%.3f Amps going through resistor.\n\n", amps);

  Serial.print("=====================================================================================================\n\n");
}
