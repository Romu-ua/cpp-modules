// Copyright 2026 hyamamot
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include "include/RPN.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Error: Usage: " << argv[0] << " <RPN>" << std::endl;
    return 1;
  }
  std::string input = argv[1];
  if (!RPN(input)) {
    return 1;
  }
  return 0;
}
