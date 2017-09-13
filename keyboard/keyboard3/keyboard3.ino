const int inputNum = 6;
const int outputNum = 4;
const int inputPins[inputNum] = {19, 18, 15, 14, 16, 10};
const int outputPins[outputNum] = {6, 7, 8, 9};
int i, j;
bool beforeState[inputNum][outputNum];
bool currentState[inputNum][outputNum];

void setup() {
  for (i = 0; i < inputNum; i++) {
    pinMode(inputPins[i], INPUT_PULLUP);
    for (j = 0; j < outputNum; j++) {
      pinMode(outputPins[j], OUTPUT);
      currentState[i][j] = HIGH;
    }
  }
   Serial.begin(9600);
}

void loop() {
  for (i = 0; i < inputNum; i++) {
    for (j = 0; j < outputNum; j++) {
      currentState[i][j] = digitalRead(inputPins[i]);
      beforeState[i][j] = currentState[i][j];
    }
  }
  for (i = 0; i < inputNum; i++) {
    for (j = 0; j < outputNum; j++) {
      Serial.print(beforeState[i][j]);
      Serial.print(":");
    }
  }
  Serial.println("");
  delay(100);
}
