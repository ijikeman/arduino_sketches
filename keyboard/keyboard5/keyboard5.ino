#include "Keyboard.h"

const int outputNum = 6;
const int inputNum = 4;
const int outputPins[outputNum] = {19, 18, 17, 16, 15, 14};
const int inputPins[inputNum] = {9, 8, 7, 6, 5};

bool currentState[outputNum][inputNum];
bool beforeState[outputNum][inputNum];
int i, j;

void setup() {
	for (i = 0; i < outputNum; i++)
	{
		pinMode(outputPins[i], OUTPUT);
		for (j = 0; j < inputNum; j++)
		{
			pinMode(inputPins, INPUT_PULLUP);
			currentState[i][j] = HIGH;
			beforeState[i][j] = HIGH;
		}
	}
	Serial.begin(9600);
}

void loop() {
	for (i = 0; i < outputNum; i++)
	{
		digitalWrite(outputPins[i], LOW);
		for (j = 0; j < inputNum; j++)
		{
			currentState[i][j] = digitalRead(inputPins[j]);
			if (currentState[i][j] != beforeState[i][j]) {
				Serial.print(i);
				Serial.print(":");
				Serial.println(j);
			}
			beforeState[i][j] = currentState[i][j];
		}
		digitalWrite(outputPins[i], HIGH);
	}
	delay(10);
}