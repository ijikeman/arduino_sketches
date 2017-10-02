void setup() {
  Serial.begin(9600);
}

void loop(){
  Serial.print(analogRead(A1));
  Serial.println(analogRead(A6));
  delay(300);
}