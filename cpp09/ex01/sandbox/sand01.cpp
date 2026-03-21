// Copyright 2026 hyamamot
#include <iostream>
#include <sstream>
#include <string>
#include <stack>

namespace {
  bool IsOperator(char c) {
    return c == '+' || c == '-' || c == '/' || c == '*';
  }

  bool IsSingleDigit(std::string& token) {
    return token.size() == 1 && std::isdigit(token[0]);
  }

  bool IsValidToken(std::string& token) {
    return token.size() == 1 &&
           (IsOperator(token[0]) || std::isdigit(token[0]));
           
  }

  int add(int a, int b) { return a + b; }
  int sub(int a, int b) { return a - b; }
  int mul(int a, int b) { return a * b; }
  int div(int a, int b) { return a / b; }
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Error: Usage: " << argv[0] << " <RPN>" << std::endl;
    return 1;
  }
  std::stack<int> st;

  std::string input = argv[1];
  std::stringstream ss(input);

  std::string token;
  int (*ops[4])(int, int) = { add, sub, mul, div };
  char symbols[4] = {'+', '-', '*', '/'};

  while (ss >> token) {
    if (!::IsValidToken(token)) {
      std::cerr << "Error: invalid input" << std::endl;
      return 1;
    }

    int num;
    if (::IsSingleDigit(token)) {
      int num = std::stoi(token);
      st.push(num);
    } else {
      int first, second;
      first = st.top();
      st.pop();
      if (st.empty()) {
        std::cout << "stack size is one" << std::endl;
        return 1;
      }
      second = st.top();
      st.pop();
      int result;
      for (int i = 0; i < 4; ++i) {
        if (symbols[i] == token[0]) {
          result = ops[i](second, first);
        }
      }
      st.push(result);
    }
  }

  if (st.size() != 1) {
    std::cerr << "stack size is not one" << std::endl;
    return 1;
  }
  std::cout << "result: " << st.top() << std::endl;
}
