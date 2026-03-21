// Copyright 2026 hyamamot
#include <iostream>
#include <string>

/*
関数ポインタの練習
*/
int add(int a, int b) {
  return a + b;
}

int sub(int a, int b) {
  return a - b;
}

int multiply(int a, int b) {
  return a * b;
}

int compute(int x, int y, int (*func)(int, int)) {
  return func(x, y);
}

int main() {
  int (*calc)(int, int);

  calc = add;
  std::cout << calc(10, 5) << std::endl;

  calc = sub;
  std::cout << calc(10, 5) << std::endl;

  std::cout << "---" << std::endl;
  std::cout << compute(3, 4, add) << std::endl;
  std::cout << compute(3, 4, multiply) << std::endl;
}
