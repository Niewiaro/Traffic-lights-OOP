// Github
// https://github.com/Niewiaro/Arduino-FORBOT-1-OOP
// inspiration
// https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink

#include <Arduino.h> // include Arduino library
#include <Led.h> // include header file of a class

#define BUTTON_PIN 7 // pin used for button
#define LED_PIN 8 // pin used for LED
#define TIME 1000 // time of blink
#define PERCENT 20 // decrease interval in %

Led *pBlinker; // pointer to Led Class Object
Led *pLedBuiltin; // pointer to Led Class Object
float *pTime= NULL; // pointer to time

void setup() { // the setup function runs once when you press reset or power the board
  float time= TIME; // set tiem as defined
  pTime= &time; // set pointer to varable

  pinMode(LED_BUILTIN, OUTPUT); // initialize digital pin LED_BUILTIN as an output (13)
  pinMode(LED_PIN, OUTPUT); // initialize digital pin LED_PIN as an output
  pinMode(BUTTON_PIN, INPUT_PULLUP); // button as imput

  Led ledBuiltin(time, LED_BUILTIN); // declaration of an object of LED_BUILTIN
  pLedBuiltin= &ledBuiltin; // set pointer to object
  Led blinker(time, LED_PIN); // declaration of an object
  pBlinker= &blinker; // set pointer to object

  ledBuiltin.blinks(5, 80, false);
}

void loop() { // the loop function runs over and over again forever
  if(digitalRead(BUTTON_PIN)== LOW){
    pLedBuiltin->blinks(3,100);
    pBlinker->blinks(3,100);
    *pTime= TIME;
  }
  else{
    *pTime= pBlinker->setInterval((int)*pTime)? TIME: *pTime* (100- PERCENT)/ 100; // conditional statement
    pBlinker->blink(); // calling an object's method
  }
}