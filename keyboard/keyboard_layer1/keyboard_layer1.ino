#define LAYER_BASE 0
#define LAYER_UPPER 1
#define LAYER_LOWER 2
const byte outputNum = 1;
const byte inputNum = 1;

#define FUNC_LT 1<<12
#define LT(layer,key) (unsigned int)(FUNC_MO | layer << 8 | key)
#define KC_H 0x63

byte currentLayer = 0;
byte beforeLayer = 0;

const int keyMap[][outputNum][inputNum] = {
  [LAYER_BASE] = {
  	{LT(LAYER_UPPER, KC_H)}
  },
  [LAYER_UPPER] = {
	{2}
  },
  [LAYER_LOWER] = {
	{3}
  }
};
void setup() {
  currentLayer = LAYER_BASE;
  Serial.begin(9600);
}

void loop() {
  Serial.print(keyMap[currentLayer][0][0]);
}

void switchlayer(byte clayer) {
}

//void switch(byte switchLayer) {
//  beforeLayer = currentLayer;
//  currentLayer switchLayer;
//}