// Copyright 2026 hyamamot
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
  }
  std::string str;

  for (int i = 1; i < argc; i++)
    str += argv[i];
  for (size_t i = 0; i < str.size(); i++)
    str[i] = std::toupper(str[i]);
  std::cout << str << std::endl;
}
