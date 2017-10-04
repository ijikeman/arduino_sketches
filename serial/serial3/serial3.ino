#include <Mouse.h>

const int mouseButton = 7;    // input pin for the mouse pushButton
const int xAxis = A1;         // joystick X axis
const int yAxis = A6;         // joystick Y axis
const bool xReverse = 0;
const bool yReverse = 0;

// parameters for reading the joystick:
int range = 20;               // output range of X or Y movement
//int threshold = range / 4;    // resting threshold
int center = range/2;       // resting position value
bool currentMouseButtonStatus = HIGH;
bool beforeMouseButtonStatus = HIGH;


void setup(){
  Serial.begin(9600);
  Serial1.begin(9600, SERIAL_8E1);
}

void loop(){
  // Mouse
  // read and scale the two axes:
  int xReading = readAxis(xAxis, xReverse);
  int yReading = readAxis(yAxis, yReverse);

  Serial.println(xReading);
  Serial.println(yReading);

  // if the mouse control state is active, move the mouse:
  if (xReading != 0) {
    Serial1.write(makeMouseData(xReading, 0));
  } else if (yReading != 0) {
    Serial1.write(makeMouseData(yReading, 1));
  }
}

int readAxis(int thisAxis, bool thisReverse) {
  int reading = analogRead(thisAxis);
  int distance;

  // map the reading from the analog input range to the output range:
  reading = map(reading, 0, 1023, 0, range);
  if (thisReverse == 0) {
    distance = reading - center;
  } else {
    distance = center - reading;
  }
  if ((distance <= 1) && (-1 <= distance)) {
    distance = 0;
  }

  // return the distance for this axis:
  return distance;
}

int makeMouseData(int currentDistance, byte xOrY) {
  byte mouseData;
  byte keyboardOrMouse = 0;
  byte minus = 0;
  byte distance;
  if (currentDistance < 0 ) {
    minus = 1;
    distance = 0 - currentDistance;
  } else {
    distance = currentDistance;
  }
  Serial.print(keyboardOrMouse);
  Serial.print(":");
  Serial.print(xOrY);
  Serial.print(":");
  Serial.print(minus);
  Serial.print(":");
  Serial.print(currentDistance);
  Serial.print(":");
  Serial.print(distance);
  mouseData = keyboardOrMouse << 7 | xOrY << 6| minus << 5 | distance;
  Serial.print(":");
  Serial.println(mouseData);
  return mouseData;
}
