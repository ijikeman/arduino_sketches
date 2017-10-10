void setup(){
  Serial.begin(9600);
  Serial1.begin(9600, SERIAL_8E1);
}

void loop(){
  for (int i=0; i < 8; i++) {
    byte val = 0b10000000 >> i;
    Serial.println(val);
    Serial1.write(val);
    digitalWrite(17, HIGH);
    delay(1000);
    digitalWrite(17, LOW);
    delay(1000);
  }
}
