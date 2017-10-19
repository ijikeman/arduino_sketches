#ifndef Ch_h
#define Ch_h
#include <vector>
class Ch {
public:
  Ch();
  void set(int *array);
  void get();
private:
  std::vector<int> v;
};
#endif
