#include "Keyboard.h"

const int InputPin = 15;
const int InputPin2 = 18;
const int InputPin3 = 19;
const int InputPin4 = 14;
const int InputPin5 = 16;
const int InputPin6 = 10;

const int OutputPin = 6;
const int OutputPin2 = 7;
const int OutputPin3 = 8;
const int OutputPin4 = 9;

void setup() {
  pinMode(InputPin, INPUT_PULLUP);
  pinMode(InputPin2, INPUT_PULLUP);
  pinMode(InputPin3, INPUT_PULLUP);
  pinMode(InputPin4, INPUT_PULLUP);
  pinMode(InputPin5, INPUT_PULLUP);
  pinMode(InputPin6, INPUT_PULLUP);
  pinMode(OutputPin, OUTPUT); // default:LOW = GND
  pinMode(OutputPin2, OUTPUT);
  pinMode(OutputPin3, OUTPUT);
  pinMode(OutputPin4, OUTPUT);
   Serial.begin(9600);
}

void loop() {
  Serial.print(digitalRead(InputPin));
  Serial.print(digitalRead(InputPin2));
  Serial.print(digitalRead(InputPin3));
  Serial.print(digitalRead(InputPin4));
  Serial.print(digitalRead(InputPin5));
  Serial.println(digitalRead(InputPin6));

//  currentState = digitalRead(OutputPin);
  // if (currentState != beforeState) {
  //   if (currentState == LOW) {
  //     digitalWrite(ledPin, HIGH);
  //     Serial.println("Push");
  //   } else {
  //     digitalWrite(ledPin, LOW);
  //     Serial.println("Release");
  //   }
  //   beforeState = currentState;
  // }
//  digitalWrite(InputPin, LOW);
  delay(100);
}
