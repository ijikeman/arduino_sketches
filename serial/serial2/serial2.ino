#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

void setup(){ 
  Serial.begin(9600);
//  Serial1.begin(9600);
    mySerial.begin(9600);
//    pinMode(2, OUTPUT);  
}

void loop(){
  while(mySerial.available()) {
//  while(Serial1.available()) {
    Serial.println((byte)Serial1.read());
    digitalWrite(17, HIGH);
	delay(1000);
  digitalWrite(17, LOW);
  delay(1000);
  }
}
