#ifndef Ch2_h
#define Ch2_h
#include "vector"
#include "Ch.h"
class Ch2 {
  public:
    Ch2();
    void set(int * array);
    void get();
  private:
     std::vector<Ch*> vc;
};
#endif

