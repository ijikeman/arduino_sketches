#include <stdio.h>

class Test {
  public:
    Test() {
      m_index = 0;
    }
    void set(unsigned int i) {
      m_b[m_index] = i;
      m_index++;
    }

    unsigned int get(unsigned int j) {
      return m_b[j];
    }

    unsigned int getIndex() {
      return m_index;
    }
  private:
    unsigned int m_b[10];
    unsigned int m_index;
};

int main() {
  unsigned int a[10];

  for (unsigned int i = 0; i< 10; i++) {
    a[i] = i*i;
    printf("%d\n", a[i]);
  }

  for (unsigned int j = 3; j < 5; j++) {
    printf("%d\n", a[j]);
  }

  printf("$$$$$$$$");
  Test test = Test();
  for (unsigned int k = 0; k < 10; k++) {
    test.set(k*k);
  }

  for (unsigned int l=0; l < 10; l++) {
     printf("%d\n", test.get(l));
  }


  Test2 test2 = Test2();
  unsigned int A = 1;
  unsigned int B = 3;
  unsigned int C = 5;
  test2.set(&A);
  test2.set(&B);
  test2.set(&C);
  for (unsigned int m = 0; m < 3; m++) {
    printf("%x\n",&test2.get(m));
  }
}
