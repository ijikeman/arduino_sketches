#include <stdio.h>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;
  std::vector<int> data(123);
  std::vector<int> data2(123, 456);

  int org_data[] = {4, 7, 11};
  std::vector<int> data3(org_data, std::end(org_data));

  std::vector<int> data4{4, 5, 6};
}
