#define LAYER_BASE 0
#define LAYER_UPPER 1;
#define LAYER_LOWER 2;
const byte LAYER_NUM = 3;
const byte outputNum = 1;
const byte inputNum = 1;
#define K_H 0x63
#define MO(layer) switch(byte layer)

byte currentLayer = 0;
byte beforeLayer = 0;
 const int keyMap[LAYER_NUM][outputNum][inputNum] = {
  {
	{MO(2)}
  },
  {
	{2}
  },
  {
	{3}
  }
};
void setup() {
  currentLayer = LAYER_BASE;
  Serial.begin(9600);
}

void loop() {
//  Serial.print(keyMap[currentLayer][1][1]);
}

void layer() {
  
}

void switch(byte switchLayer) {
  beforeLayer = currentLayer;
  currentLayer switchLayer;
}