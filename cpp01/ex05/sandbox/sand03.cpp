// Copyright 2026 hyaammot
#include <iostream>
#include <string>

/*
関数ポインタの練習
*/
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }

int main() {
  int (*operations[3])(int, int) = {add, sub, mul};

  for (int i = 0; i < 3; ++i) {
    std::cout << operations[i](10, 5) << std::endl;
  }
}
