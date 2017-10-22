const int outputNum = 5;
const int inputNum = 6;
const int outputPins[outputNum] = {10, 16, 14, 15, 18};
const int inputPins[inputNum] = {21, 5, 6, 20, 8, 9 };

bool currentState[outputNum][inputNum];
bool beforeState[outputNum][inputNum];
int i, j;

void setup() {
	for (i = 0; i < outputNum; i++) {
		pinMode(outputPins[i], OUTPUT);
		for (j = 0; j < inputNum; j++) {
			pinMode(inputPins[j], INPUT_PULLUP);
			currentState[i][j] = HIGH;
			beforeState[i][j] = HIGH;
		}
    digitalWrite(outputPins[i], HIGH);
	}
	Serial.begin(9600);
}

void loop() {
	for (i = 0; i < outputNum; i++) {
		digitalWrite(outputPins[i], LOW);
		for (j = 0; j < inputNum; j++) {
      currentState[i][j] = digitalRead(inputPins[j]);
			if (currentState[i][j] != beforeState[i][j]) {
			  beforeState[i][j] = currentState[i][j];
			}
      Serial.print(beforeState[i][j]);
      Serial.print(":");
		}
    digitalWrite(outputPins[i], HIGH);
	}
 Serial.println("");
}

