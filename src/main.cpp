// Github
// https://github.com/Niewiaro/Arduino-FORBOT-1-OOP
// inspiration
// https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink

#include <Arduino.h> // include Arduino library
#include <Led.h> // include header file of a class

#define BUTTON_PIN 7 // pin used for button
#define RED_LED_PIN 10 // pin used for RED LED
#define YELLOW_LED_PIN 9 // pin used for YELLOW LED
#define GREEN_LED_PIN 8 // pin used for GREEN LED
#define TIME 1000 // time of blink
#define PERCENT 20 // decrease interval in %

Led *pLedBuiltin; // pointer to Led Class Object
Led *pRedLed; // pointer to Led Class Object
Led *pYellowLed;
Led *pGreenLed;
float *pTime= NULL; // pointer to time
bool on= false;

void setup() { // the setup function runs once when you press reset or power the board
  float time= TIME; // set tiem as defined
  pTime= &time; // set pointer to varable

  pinMode(LED_BUILTIN, OUTPUT); // initialize digital pin LED_BUILTIN as an output (13)
  pinMode(RED_LED_PIN, OUTPUT); // initialize digital pin RED_LED_PIN as an output
  pinMode(YELLOW_LED_PIN, OUTPUT); // initialize digital pin YELLOW_LED_PIN as an output
  pinMode(GREEN_LED_PIN, OUTPUT); // initialize digital pin GREEN_LED_PIN as an output
  pinMode(BUTTON_PIN, INPUT_PULLUP); // button as imput

  Led ledBuiltin(time, LED_BUILTIN); // declaration of an object of LED_BUILTIN
  pLedBuiltin= &ledBuiltin; // set pointer to object
  Led redLed(time, RED_LED_PIN); // declaration of an object of RED_LED_PIN
  pRedLed= &redLed; // set pointer to object
  Led yellowLed(time, YELLOW_LED_PIN); // declaration of an object of YELLOW_LED_PIN
  pYellowLed= &yellowLed; // set pointer to object
  Led greenLed(time, GREEN_LED_PIN); // declaration of an object of GREEN_LED_PIN
  pGreenLed= &greenLed; // set pointer to object

  ledBuiltin.blinks(5, 80, true);
  redLed.blinks(5, 80, true);
  yellowLed.blinks(5, 80, true);
  greenLed.blinks(5, 80, true);

  ledBuiltin.power(false);
}

void loop() { // the loop function runs over and over again forever
  if(on) {
    pRedLed->power(on);
    pYellowLed->power(on);
    pGreenLed->power(on);
    on= false;
  }
  else {
    pRedLed->power(on);
    pYellowLed->power(on);
    pGreenLed->power(on);
    on= true;
  }
  delay(1000);
}