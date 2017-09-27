const int inputNum = 6;
const int outputNum = 4;
const int inputPins[inputNum] = {19, 18, 15, 14, 16, 10};
const int outputPins[outputNum] = {6, 7, 8, 9};
int i, j;
bool beforeState[outputNum][inputNum];
bool currentState[outputNum][inputNum];

void setup() {
  for (i = 0; i < outputNum; i++) {
    pinMode(outputPins[i], OUTPUT);
    digitalWrite(outputPins[i], HIGH);
    for (j = 0; j < inputNum; j++) {
      pinMode(inputPins[j], INPUT_PULLUP);
      currentState[i][j] = HIGH;
      beforeState[i][j] = HIGH;
    }
  }
  Serial.begin(9600);
}

void loop() {
  for (i = 0; i < outputNum; i++) {
    digitalWrite(outputPins[i], LOW);
    for (j = 0; j < inputNum; j++) {
      currentState[i][j] = digitalRead(inputPins[j]);
      beforeState[i][j] = currentState[i][j];
      Serial.print(beforeState[i][j]);
      Serial.print(":");
    }
    digitalWrite(outputPins[i], HIGH);
  }
  Serial.println("");
  delay(10);
}
