void setup() {
  Serial.begin(9600);
  Serial1.begin(9600, SERIAL_8E1);
  pinMode(17, OUTPUT);
}

void loop() {
  if (Serial1.available()) {
    char val = Serial1.read();
    Serial.println(val);
    digitalWrite(17, HIGH);
  }
  digitalWrite(17, LOW);
  delay(10);
}
