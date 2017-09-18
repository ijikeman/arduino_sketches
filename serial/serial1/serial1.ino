#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

void setup(){ 
    mySerial.begin(9600);
    Serial1.begin(9600);
//    pinMode(2, INPUT);
}

void loop(){
    mySerial.write(45);
//    Serial1.write(45);
    digitalWrite(17, HIGH);
    delay(1000);
    digitalWrite(17, LOW);
    delay(1000);
}
