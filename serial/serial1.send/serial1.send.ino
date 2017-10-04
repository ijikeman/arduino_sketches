void setup() {
  Serial1.begin(9600, SERIAL_8E1);
  pinMode(17, OUTPUT);
}

void loop() {
  Serial1.write("Hello");
  digitalWrite(17, HIGH);
  delay(1000);
  digitalWrite(17, LOW);
  delay(1000);
}
