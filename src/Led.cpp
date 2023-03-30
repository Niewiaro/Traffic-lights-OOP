#include <Arduino.h>
#include <Led.h>

Led::Led(int interval, int pin): time(interval), ledPin(pin) { // constructor with initialization list
    digitalWrite(ledPin, LOW);
} 

bool Led::setInterval(int interval) {
    if(interval<= 0)
        return true;
    time= interval;
    return false;
}

void Led::blink() {
    digitalWrite(ledPin, HIGH);
    delay(time);
    digitalWrite(ledPin, LOW);
    delay(time);
}

void Led::blinks(int quantity, int blinksInterval, bool stayHigh) {
    for(int i= 0; i< quantity; i++) {
        digitalWrite(ledPin, HIGH);
        delay(blinksInterval);
        digitalWrite(ledPin, LOW);
        delay(blinksInterval);
    }

    if(stayHigh)
        digitalWrite(ledPin, HIGH);
}

bool Led::power(bool power) {
    if(power) {
        digitalWrite(ledPin, HIGH);
        return true;
    }
    digitalWrite(ledPin, LOW);
    return false;
}