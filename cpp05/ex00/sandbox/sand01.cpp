// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include <exception>

// 例外処理の練習

int main() {
  std::string str = "123X";

  try {
    int num = 0;
    for (int i = 0; i < str.size(); ++i) {
      num *= 10;
      switch (str[i]) {
        case '0':
          num += 0;
          break;
        case '1':
          num += 1;
          break;
        case '2':
          num += 2;
        default:
          throw std::runtime_error("contains non-numeric characters");
      }
    }
    std::cout << num << std::endl;
  } catch (const std::runtime_error& e) {
    std::cout << e.what() << std::endl;
  }
}
