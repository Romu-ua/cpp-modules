// Copyright 2026 hyamamot
#include <iostream>
#include <string>
#include <cstdlib>

/*
気になった関数の挙動を調査
公式ドキュメントより、例外が投げられている
*/
int main(int argc, char *argv[]) {
  if (argc != 2)
    return 1;

  std::string str = argv[1];

  //int num = std::stoi(str);
  //std::cout << num << std::endl;

  //std::cout << std::endl;
  //int max = 2147483647;
  //std::cout << max << std::endl;

  std::cout << std::endl;
  char* endptr;
  double val = strtod(str.c_str(), &endptr);

  std::cout << "変換された数値: " << val << std::endl;
  std::cout << "残りの文字:" << endptr << std::endl;

  // 値がないときは0になる。
  int i = static_cast<int>(val);

  std::cout << "int: " << i << std::endl;
}
