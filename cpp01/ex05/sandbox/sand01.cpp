// Copyright 2026 hyamamot
#include <iostream>
#include <string>

/*
関数ポインタの練習
*/
int add(int a, int b) {
  return a + b;
}

int main() {
  int (*func)(int, int);
  func = add;

  int result = func(3, 4);
  std::cout << result << std::endl;
}
