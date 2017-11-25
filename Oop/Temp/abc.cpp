# include<stdio.h>

class Test {
  public:
    Test() {
      m_index = 0;
    }
    void set(int num) {
      m_num[m_index] = num;
      m_index++;
    }
    int get(int num) {
      return m_num[num];
    }
  private:
    int m_num[10];
    int m_index;
};

class Test3 {
  public:
    Test3() {
      m_index = 0;
    }
    void set(Test * test) { // Test Classのポインタで格納
      m_num[m_index] = test;
      m_index++;
    }
    Test * get(int num) {
      return m_num[num];
    }
  private:
    Test * m_num[5]; // Test Class オブジェクトのポインタを配列で格納
    int m_index;
};

int main(void) {
  Test * test = new Test();
  test->set(5);
  test->set(3);
  test->set(9);
  printf("test1 = %x\n", test);
  Test * testx = new Test();
  testx->set(67);
  testx->set(88);
  printf("test1 = %x\n", testx);

  Test3 test3 = Test3();
  test3.set(test);
  test3.set(testx);

for (int i=0; i < 2; i++) {
  printf("test3 = %d\n", test3.get(i)->get(1));
}
delete test;
delete testx;
}
