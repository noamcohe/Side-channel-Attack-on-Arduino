// Include the Keypad library
#include <Keypad.h>


const int buzzerPin = 12; // declaring the PWM pin</p><p>void setup() {
 
// Constants for row and column sizes
const byte ROWS = 4;
const byte COLS = 4;
 
// Array to represent keys on keypad
char hexaKeys[ROWS][COLS] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};


/*
  {'s4', 's8', 's12', 's16'},
  {'s3', 's7', 's11', 's15'},
  {'s2', 's6', 's10', 's14'},
  {'s1', 's5', 's9', 's13'}
*/

 
// Connections to Arduino
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
 
// Create keypad object
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
 
void setup()
{
  // Setup serial monitor
  Serial.begin(9600);  
}
 
void loop()
{
  // Get key value if pressed
  char customKey = customKeypad.getKey();
 
  if (customKey) {
    
    // Print key value to serial monitor
    Serial.println(customKey);

    makeButtonSound(customKey);
  }
}

// 400, 300, 2000, 

void makeButtonSound(char button)
{
  if (button == '1') { return makeSound(1000); }
  if (button == '2') { return makeSound(500); }
  if (button == '3') { return makeSound(600); }
  if (button == '4') { return makeSound(900); }
  if (button == '5') { return makeSound(1100); }
  if (button == '6') { return makeSound(700); }
  if (button == '7') { return makeSound(800); }
  if (button == '8') { return makeSound(1200); }
  if (button == '9') { return makeSound(1400); }
  if (button == '0') { return makeSound(1300); }
  //  if (button == 'A') { return makeSound(); }
  //  if (button == 'B') { return makeSound(); }
  if (button == 'C') { return makeSound(29); }
  if (button == 'D') { 
    for (int i=20; i<30; i++){
      makeSound(i);
      delay(80);
    }
  }
}


//
void makeSound(int indexOfBeep)
{
  for (int i = 0; i < 5; i++)
  {
    tone(buzzerPin, indexOfBeep);
    delay(750);
    noTone(buzzerPin);
    delay(100);
  }
}
