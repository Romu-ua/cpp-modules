// Copyright 2026 hyamamot
#include <iostream>
#include <exception>
#include <string>

// 例外クラスを作ってみる

// destructorでnoexceptionをつけないとダメらしい
class MyException : public std::exception {
  std::string message;

 public:
  MyException(const std::string& mes) : message(mes) {}
  ~MyException() throw() {}

  const char* what() const throw() {
    return message.c_str();
  }
};

void test (int x) {
  if (x < 0) {
    throw MyException("x must not be negative.");
  }
}

int main() {
  try {
    test(-1);
  } catch (const MyException& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}
