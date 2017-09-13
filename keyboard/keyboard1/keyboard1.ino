const int inputPin = 18;     // the number of the pushbutton pin
const int outputPin = 6;
const int ledPin =  17;      // the number of the LED pin

// variables will change:
bool inputState = HIGH;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT); // default:LOW 0V
  // initialize the pins:
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
  digitalWrite(inputPin, HIGH); // = INPUT_PULLUP
  digitalWrite(outputPin, LOW); // default:LOW
  Serial.begin(9600);
}

void loop(){
  // read the state of the pushbutton value:
  inputState = digitalRead(inputPin);

  if (inputState == LOW) { // not PUSH 
    // turn LED on:
    digitalWrite(ledPin, HIGH); 
    delay(30);
    while(inputState == LOW){
      inputState = digitalRead(inputPin);
      // Keyboard.press(ctrlKey);
      Serial.println("button push");
    }
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
    Serial.println("button release");
  }
  delay(100);
}
