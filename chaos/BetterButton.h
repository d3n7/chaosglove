#ifndef Buttons_h
#define Buttons_h

#include "Arduino.h"

class BetterButton
{
  public:
    BetterButton(int _buttonPin, int _val);
    
    void process();
    void pressHandler(void (*f)(int));
    void releaseHandler(void (*f)(int));
    void (*pressCallback)(int);
    void (*releaseCallback)(int);

    int val;
    int buttonPin;
    bool buttonState;
    bool lastButtonState;

  private:
};

#endif
