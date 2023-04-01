// Github
// https://github.com/Niewiaro/Traffic-lights-OOP

#include <Arduino.h> // include Arduino library
#include <Led.h> // include header file of a class

#define BUTTON_PIN 7 // pin used for button
#define RED_LED_PIN 10 // pin used for RED LED
#define YELLOW_LED_PIN 9 // pin used for YELLOW LED
#define GREEN_LED_PIN 8 // pin used for GREEN LED
#define TIME 1000 // time of blink
#define PERCENT 20 // decrease interval in %
#define NUMBER_OF_LED 4 // total in use

Led* ledArr[NUMBER_OF_LED]; // arr of pointers
bool power= false;

void insertAtEnd(Led* arr[], int &n, Led *e) {
  if(n< NUMBER_OF_LED)
    arr[n] = e;
  n++;
}

void blinks(Led* arr[], int size= NUMBER_OF_LED, int quantity= 5, int blinksInterval= 80, bool stayHigh= true, int delayTime= 0) {
  for(int i= 0; i< size; i++)
    arr[i]->blinks(quantity, blinksInterval, stayHigh);
  delay(delayTime);
}

bool changeState(Led* arr[], int size= NUMBER_OF_LED, bool isOn= true, int delayTime= 0) {
  for(int i= 0; i< size; i++)
    arr[i]->power(isOn);
  delay(delayTime);
  if(isOn)
    return false;
  return true;
}

void setup() { // the setup function runs once when you press reset or power the board
  pinMode(LED_BUILTIN, OUTPUT); // initialize digital pin LED_BUILTIN as an output (13)
  pinMode(RED_LED_PIN, OUTPUT); // initialize digital pin RED_LED_PIN as an output
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // button as imput

  Led *pLedBuiltin; // pointer to Led Class Object
  Led *pRedLed; // pointer to Led Class Object
  Led *pYellowLed;
  Led *pGreenLed;

  int iterator= 0;

  Led ledBuiltin(TIME, LED_BUILTIN); // declaration of an object of LED_BUILTIN
  insertAtEnd(ledArr, iterator, pLedBuiltin= &ledBuiltin);
  Led redLed(TIME, RED_LED_PIN); // declaration of an object of RED_LED_PIN
  insertAtEnd(ledArr, iterator, pRedLed= &redLed);
  Led yellowLed(TIME, YELLOW_LED_PIN); 
  insertAtEnd(ledArr, iterator, pYellowLed= &yellowLed);
  Led greenLed(TIME, GREEN_LED_PIN); 
  insertAtEnd(ledArr, iterator, pGreenLed= &greenLed);

  blinks(ledArr);
  changeState(ledArr, NUMBER_OF_LED, false, TIME);
}

void loop() { // the loop function runs over and over again forever
  //power= changeState(ledArr, NUMBER_OF_LED, power);
  ledArr[0]->power();
  ledArr[1]->power();
  ledArr[2]->power(0);
  ledArr[3]->power(0);
  delay(TIME);
  while (digitalRead(BUTTON_PIN) == HIGH) {} // wait until press of the button
  
  ledArr[0]->power(0);
  ledArr[1]->power();
  ledArr[2]->power();
  ledArr[3]->power(0);
  delay(TIME);
  while (digitalRead(BUTTON_PIN) == HIGH) {} // wait until press of the button

  ledArr[0]->power(0);
  ledArr[1]->power(0);
  ledArr[2]->power(0);
  ledArr[3]->power();
  delay(TIME);
  while (digitalRead(BUTTON_PIN) == HIGH) {} // wait until press of the button

  ledArr[0]->power(0);
  ledArr[1]->power(0);
  ledArr[2]->power();
  ledArr[3]->power(0);
  delay(TIME);
  while (digitalRead(BUTTON_PIN) == HIGH) {} // wait until press of the button
}