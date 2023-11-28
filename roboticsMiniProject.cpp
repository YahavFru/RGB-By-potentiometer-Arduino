#include <Arduino.h>

#define redPin 9
#define greenPin 10
#define bluePin 11

#define redControl A0
#define greenControl A1
#define blueControl A2

#define buttonLPin 2
#define buttonRPin 3
int* savedRGB[3] = {0, 0, 0};

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  pinMode(redControl, INPUT);
  pinMode(blueControl, INPUT);
  pinMode(greenControl, INPUT);

  pinMode(buttonLPin, INPUT);
  pinMode(buttonRPin, INPUT);
}

void loop() {
  if(takesInput(digitalRead(buttonLPin), takesInput(digitalRead(buttonRPin), savedRGB) == True)
  
}

void lightWriteRGB(int red, int green, int blue){
  red = map(red, 0, 1023, 0, 255);
  green = map(green, 0, 1023, 0, 255);
  blue = map(blue, 0, 1023, 0, 255);
  digitalWrite(redControl, red);
  digitalWrite(greenControl, red);
  digitalWrite(redControl, red);
}

// When both buttons are pressed, save current RGB state, R goes back to saved, L goes back to input mode

bool takesInput(int btnL, int btnR, int* rgb[3]) {
  if (btnL == 1){
    delay(100);
    if(btnR == 1){
      savedRGB[0] = rgb[0];
      savedRGB[1] = rgb[1];
      savedRGB[2] = rgb[2];
      return false;
    }
    else{
      
    }
  }
}