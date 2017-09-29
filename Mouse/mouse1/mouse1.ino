#include "Mouse.h"

const int mouseButton = 7;    // input pin for the mouse pushButton
const int xAxis = A1;         // joystick X axis
const int yAxis = A6;         // joystick Y axis

// parameters for reading the joystick:
int range = 12;               // output range of X or Y movement
int responseDelay = 5;        // response delay of the mouse, in ms
int threshold = range / 4;    // resting threshold
int center = range / 2;       // resting position value
bool currentMouseButtonStatus = HIGH;
bool beforeMouseButtonStatus = HIGH;

void setup() {
  // take control of the mouse:
  Mouse.begin();
  pinMode(mouseButton, INPUT_PULLUP);
}

void loop() {
  // read and scale the two axes:
  int xReading = readAxis(xAxis);
  int yReading = readAxis(yAxis);

  // if the mouse control state is active, move the mouse:
  Mouse.move(xReading, yReading, 0);

  // read the mouse button and click or not click:
  // if the mouse button is pressed:
  currentMouseButtonStatus = digitalRead(mouseButton);
  if (beforeMouseButtonStatus != currentMouseButtonStatus) {
    beforeMouseButtonStatus = currentMouseButtonStatus;
    if (currentMouseButtonStatus == LOW) {
      Mouse.press(MOUSE_LEFT);
    } else {
      Mouse.release(MOUSE_LEFT);
    }
  }
  delay(responseDelay);
}

/*
  reads an axis (0 or 1 for x or y) and scales the analog input range to a range
  from 0 to <range>
*/

int readAxis(int thisAxis) {
  // read the analog input:
  int reading = analogRead(thisAxis);

  // map the reading from the analog input range to the output range:
  reading = map(reading, 0, 1023, 0, range);

  // if the output reading is outside from the rest position threshold, use it:
  int distance = reading - center;

  if (abs(distance) < threshold) {
    distance = 0;
  }

  // return the distance for this axis:
  return distance;
}
