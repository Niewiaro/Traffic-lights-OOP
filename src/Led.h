#ifndef LED_H // if not define then define file
#define LED_H

class Led {
public: // public section, accessable for everyone
    Led(int interval= 1000, int led= 13); // constructor with parameters and inital values
    bool setInterval(int interval); // setting method
    void blink(); // blinking method
    void blinks(int quantity= 3, int blinksInterval= 100, bool stayHigh= false); // blinking method
    bool power(bool power= true);

private: // private part
    int time;
    int ledPin;
};

#endif