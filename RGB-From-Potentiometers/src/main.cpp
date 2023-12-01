#include <Arduino.h>

#define redPin 9
#define greenPin 10
#define bluePin 11

#define redControl A0
#define greenControl A1
#define blueControl A2

#define buttonLPin 2
#define buttonRPin 3

int prevState = 2;

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



void lightWriteRGB(int rgb[3]){
  rgb[0] = map(rgb[0], 0, 1023, 0, 255);
  rgb[1] = map(rgb[1], 0, 1023, 0, 255);
  rgb[2] = map(rgb[2], 0, 1023, 0, 255);
  digitalWrite(redControl, rgb[0]);
  digitalWrite(greenControl, rgb[1]);
  digitalWrite(redControl, rgb[2]);
}

// When both buttons are pressed, save current RGB state, R goes back to saved, L goes back to input mode

int currentState(bool btnlState, bool btnrState, int savedRGB[3], int rgb[3], int prev){
   if(btnlState) {
    delay(100);
    if (btnrState){
      // savedRGB[0] = rgb[0];
      // savedRGB[1] = rgb[1];
      // savedRGB[2] = rgb[2];
      return 0;
    } else {
        // lightWriteRGB(savedRGB);
        return 1;
    }
  } else if (btnrState)
  {
    // lightWriteRGB(rgb);
    return 2;
  } else {
    return prev;
  }
}

void loop() {
  int savedRGB[3] = {0, 0 ,0};
  int red = analogRead(redControl);
  int blue = analogRead(blueControl);
  int green = analogRead(greenControl);
  int rgb[3] = {red, green ,blue};
  bool btnlState = digitalRead(buttonLPin);
  bool btnrState = digitalRead(buttonRPin);
  switch (currentState(btnlState, btnrState, savedRGB, rgb, prevState)){
    case 0:
      savedRGB[0] = rgb[0];
      savedRGB[1] = rgb[1];
      savedRGB[2] = rgb[2];
    case 1:
      lightWriteRGB(savedRGB);
    case 2:
      lightWriteRGB(rgb);
  }
  prevState = currentState(btnlState, btnrState, savedRGB, rgb, prevState);
}