// Copyright 2026 hyamamot
#include <iostream>
#include <string>

int main() {
  std::string str = "HI THIS IS BRAIN";
  std::string* stringPTR = &str;
  std::string& stringREF = str;


  std::cout << "print val" << std::endl;
  std::cout << "str: " << str << std::endl;
  std::cout << "*stringPTR: " << *stringPTR << std::endl;
  std::cout << "&stringREF" << stringREF << std::endl;

  std::cout << std::endl;
  std::cout << "== address ==" << std::endl;

  std::cout << "&str: " << &str << std::endl;
  std::cout << "stringPTR: " << stringPTR << std::endl;
  std::cout << "&stringREF: " << &stringREF << std::endl;

  std::cout << std::endl;
  std::cout << "== changed val (pointer) ==" << std::endl;
  *stringPTR = "changed by pointer";
  std::cout << "str: " << str << std::endl;

  std::cout << std::endl;
  std::cout << "== changed val (ref) ==" << std::endl;
  stringREF = "changed by ref";
  std::cout << "str: " << str << std::endl;
}
