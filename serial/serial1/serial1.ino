#include <SoftwareSerial.h>

SoftwareSerial mySerial(10,16); // RX, TX

void setup(){ 
    //mySerial.begin(9600);
    //Serial.begin(9600);
    Serial1.begin(9600);
}

void loop(){
//    mySerial.write("HelloWorld");
//    Serial.write("Hey");
   Serial1.write("Hey");
    digitalWrite(17, HIGH);
    delay(1000);
    digitalWrite(17, LOW);
    delay(1000);
}
