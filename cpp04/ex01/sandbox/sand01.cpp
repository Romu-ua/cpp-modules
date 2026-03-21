// Copyright 2026 hyamamot
#include <iostream>

/*
deep copyの練習

ここに継承が入ってくるのでちょっとめんどくさい
*/
class A {
  int *data;

 public:
  // コンストラクタ
  A(int value) {
    std::cout << "constructor" << std::endl;
    data = new int(value);
  }
  // コピーコンストラクタ
  A(const A& other) {
    std::cout << "copy constructor" << std::endl;
    data = new int(*other.data);
  }

  // コピー演算代入子
  A& operator=(const A& other) {
    std::cout << "copy operator" << std::endl;
    if (this != &other) {
      delete data;
      data = new int(*other.data);
    }
    return *this;
  }

  // デストラクタ
  ~A() {
    std::cout << "destructor" << std::endl;
    delete data;
  }
};

int main() {
  A a(42);
  A b = a;
}
