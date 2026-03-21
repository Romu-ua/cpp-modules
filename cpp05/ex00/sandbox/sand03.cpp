// Copyright 2026 hyamamot
#include <iostream>
#include <string>

// 例外が捕捉されない場合はstd::terminateが呼び出されて以上終了

int StringToInt(const std::string& str) {
  int num = 0;
  for (int i = 0; i < str.size(); ++i) {
    num *= 10;
    switch (str[i]) {
      case '0':  num += 0;  break;
      case '1':  num += 1;  break;
      case '2':  num += 2;  break;
      case '3':  num += 3;  break;
      case '4':  num += 4;  break;
      case '5':  num += 5;  break;
      case '6':  num += 6;  break;
      case '7':  num += 7;  break;
      case '8':  num += 8;  break;
      case '9':  num += 9;  break;
      default:
        throw std::runtime_error("contain non-numeric character");
    }
  }
  return num;
}

int main() {
  std::string str = "123X";
  int num = StringToInt(str);
  std::cout << num << std::endl;
}
