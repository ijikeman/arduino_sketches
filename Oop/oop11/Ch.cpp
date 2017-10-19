#include "Ch.h"
#include <stdio.h>

Ch::Ch() {
}
void Ch::set(int *array) {
  v.push_back(3);  
  v.push_back(8);  
}
void Ch::get() {
  for (std::vector<int>::iterator itr = v.begin(); itr!=v.end();itr++) {
    printf("%d", *itr);
  }
  printf("%d", v[0]);
  printf("%d", v[1]);
}
