#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 16); // RX, TX

void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
//    mySerial.begin(9600);
//  while(!Serial1) {
//    digitalWrite(17, HIGH);
//  }
}

void loop(){
//  while(mySerial.available()) {
//  while(Serial1.available()) {
//char val = mySerial.read();
char val = Serial1.read();
Serial.println(val);
    digitalWrite(17, HIGH);
	delay(1000);
  digitalWrite(17, LOW);
  delay(1000);
//  }
}
