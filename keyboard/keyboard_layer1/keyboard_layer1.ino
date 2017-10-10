#define BASE 0
#define UPPER 1
#define LOWER 2
const byte outputNum = 1;
const byte inputNum = 1;

#define FUNC_LT 1<<12
#define LT(layer,key) (unsigned int)(FUNC_LT | layer << 8 | key)
#define KC_H 0x63

byte currentLayer = 0;
byte beforeLayer = 0;

const int keyMap[][outputNum][inputNum] = {
  [BASE] = {
  	{LT(LOWER, KC_H)}
  },
  [UPPER] = {
	{2}
  },
  [LOWER] = {
	{3}
  }
};
void setup() {
  currentLayer = BASE;
  Serial.begin(9600);
}

void loop() {
  Serial.println(keyMap[currentLayer][0][0]);
  delay(500);
}

void switchlayer(byte clayer) {
}

//void switch(byte switchLayer) {
//  beforeLayer = currentLayer;
//  currentLayer switchLayer;
//}