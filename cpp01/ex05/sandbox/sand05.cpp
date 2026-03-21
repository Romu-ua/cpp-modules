// Copyright 2026 hyamamot
#include <iostream>
#include <string>

/*
メンバ関数ポインタの練習
*/

class Test {
 public:
  void a() {
    std::cout << "A" << std::endl;
  }

  void b() {
    std::cout << "B" << std::endl;
  }

  void c() {
    std::cout << "C" << std::endl;
  }
};

int main() {
  Test t;

  void (Test::*funcs[3])() = {&Test::a, &Test::b, &Test::c};

  (t.*funcs[0])();
  (t.*funcs[1])();
  (t.*funcs[2])();
}
