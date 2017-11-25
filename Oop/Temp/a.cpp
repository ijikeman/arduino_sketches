#include <stdio.h>

class Test {
  public:
    Test(int i) {
      m_i = i;
    }
    int get() {
      return m_i;
    }
  private:
    int m_i;

  ~Test() {
  }
};

class Test2 {
  public:
    Test2() {
      index = 0;
    }
    void add(Test * test) {
      array[index] = test;
      printf("index=%d\n", index);
      index++;
    }
    Test * get(int num) {
      printf("num=%d\n", num);
      printf("array=%x\n", array[num]);
       return array[num];
    }
   private:
    Test * array[5];
    int index;
};

int main() {
  for (int j=0; j < 3; j++) {
    Test *  test = new Test(1);
    printf("%x\n", test);
  }

  Test2 test2 = Test2();
  for (int j=0; j < 3; j++) {
    test2.add(new Test(j));
  }

  for (int k=0; k < 3; k++) {
    printf("%x\n", test2.get(k));
  }
}
