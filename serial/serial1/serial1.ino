#include <SoftwareSerial.h>

SoftwareSerial mySerial(10,16); // RX, TX

void setup(){ 
    //mySerial.begin(9600);
    //Serial.begin(9600);
    Serial1.begin(9600, SERIAL_8E1);
}

void loop(){
//    mySerial.write("HelloWorld");
//    Serial.write("Hey");
   for (int i = 0; i < 100; i++) {
    Serial1.write(i);
    digitalWrite(17, HIGH);
    delay(1000);
    digitalWrite(17, LOW);
    delay(1000);
  }
}
