#ifndef Ch_h
#define Ch_h
#include <vector>
class Ch {
public:
  Ch();
//  void set(int *array);
  void set(int b);
  void get();
private:
  int a;
  std::vector<int> v;
};
#endif
