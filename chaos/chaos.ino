//CHAOS GLOVE BY CAMERON GLASS
#include <BLEMIDI_Transport.h>
#include <hardware/BLEMIDI_ESP32.h>
#include "BetterButton.h"
//allows normal MIDI messages to be sent over bluetooth:
BLEMIDI_CREATE_INSTANCE("PLEASE",MIDI);

//accelerometer low and high
int lowA = 1500;
int highA = 2250;

//pins and vars for accelerometer + switches
int xPin = A4;
int yPin = A5;
int xSwitch = 17;
int ySwitch = 18;
int xVal = 0;
int yVal = 0;
int xVal2B = 0;
int yVal2B = 0;
int prevX = 0;
int prevY = 0;

//control number switcher buttons
int controlUPin = 23;
int controlDPin = 19;
BetterButton controlU(controlUPin, 1); //19 is controlU pin
BetterButton controlD(controlDPin, 0); //23 is controlD pin
int controlN = 0;

//fx buttons
int fx1Pin = 21;
int fx2Pin = 22;
BetterButton fx1(fx1Pin, 1); //19 is controlU pin
BetterButton fx2(fx2Pin, 0); //23 is controlD pin

//functions for control number switcher buttons
//if controlU is pressed, controlN++, otherwise (if its not already 0), controlN--
void controlPress(int val) {
  if (val==1) controlN++;
  else if (controlN!=0) controlN--;
}

void controlRelease(int val) {
  delay(10);
}

void fxPress(int val) {
  MIDI.sendNoteOn(36+val,127,1);
}

void fxRelease(int val) {
  MIDI.sendNoteOff(36+val,0,1);
  delay(10);
}

void setup()
{
  MIDI.begin(10);
  
  //this one just makes a little blue LED on the ESP32 light up
  pinMode(5, OUTPUT);
  
  pinMode(xSwitch, INPUT);
  pinMode(ySwitch, INPUT);
  pinMode(controlUPin, INPUT);
  pinMode(controlDPin, INPUT);
  pinMode(fx1Pin, INPUT);
  pinMode(fx2Pin, INPUT);

  //setting up better buttons
  controlU.pressHandler(controlPress);
  controlD.pressHandler(controlPress);
  controlU.releaseHandler(controlRelease);
  controlD.releaseHandler(controlRelease);
  fx1.pressHandler(fxPress);
  fx2.pressHandler(fxPress);
  fx1.releaseHandler(fxRelease);
  fx2.releaseHandler(fxRelease);
}

void loop()
{
  //switch control numbers if buttons are pressed
  controlU.process();
  controlD.process();
  fx1.process();
  fx2.process();
  //read acc values, send them if they switches are enabled
  accProcess();
}

void accProcess() {
  if (digitalRead(xSwitch)==HIGH) {
    xVal2B = analogRead(xPin);
    xVal+=(xVal2B-xVal)/2;//smoothing function
    int mappedX = map(constrain(xVal,lowA,highA),lowA,highA,0,127);//mapping to midi range
    if (abs(mappedX/2-prevX/2)>0) MIDI.sendControlChange(1+controlN*3,mappedX,1);//sending control change
    prevX = mappedX;
    delay(10);
  }
  if (digitalRead(ySwitch)==HIGH) {
    yVal2B = analogRead(yPin);
    yVal+=(yVal2B-yVal)/2;//smoothing function
    int mappedY = map(constrain(yVal,lowA,highA),lowA,highA,0,127);//mapping to midi range
    if (abs(mappedY/2-prevY/2)>0) MIDI.sendControlChange(2+controlN*3,mappedY,1);//sending control change
    prevY = mappedY;
    delay(10);
  }
}
