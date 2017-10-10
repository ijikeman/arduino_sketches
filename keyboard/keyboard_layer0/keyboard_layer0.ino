const int LAYER_BASE = 0;
const int LAYER_UPPER = 1;
const int LAYER_LOWER = 2;
const int LAYER_NUM = 3;
const int outputNum = 1;
const int inputNum = 1;
#include <stdio.h>
#define FUNC_MO 1<<12
#define MO(layer,key) (unsigned int)(FUNC_MO | layer << 8 | key)
#define KC_H 0x63

int currentLayer = 0;
int beforeLayer = 0;
const int keyMap[LAYER_NUM][outputNum][inputNum] = {
  {
  	{MO(LAYER_LOWER, KC_H)}
  },
  {
	{2}
  },
  {

	{3}
  }
};

int main() {
  printf("%d", keyMap[0][0][0]);
}
