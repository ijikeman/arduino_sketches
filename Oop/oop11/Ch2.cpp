#include "Ch2.h"
#include "Ch.h"
#include "stdio.h"
#include <vector>

Ch2::Ch2() {
}

void Ch2::set(int * array) {
  for (int i=0; i < 3; i++) {
printf("Ch2::SET %d\n", array[i]);
    Ch *ch = new Ch();
    (*ch).set(array[i]);
    vc.push_back(ch);
  }
}

void Ch2::get() {
printf("Ch2::GET Start\n");
  for (std::vector<Ch*>::iterator itr = vc.begin(); itr != vc.end(); itr++) {
     (**itr).get();
  } 
}

