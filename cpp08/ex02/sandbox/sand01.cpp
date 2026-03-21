// Copyright 2026 hyamamot
#include <iostream>
#include <stack>

/*
stackについて学習
*/

int main() {
  // tutorial
  std::stack<int> st;
  st.push(10);
  st.push(5);

  std::cout << "top: " << st.top() << std::endl;
  st.pop();
  std::cout << "top after pop: " << st.top() << std::endl;

  st.push(20);
  st.push(30);
  st.push(40);

  while (!st.empty()) {
    std::cout << st.top() << std::endl;
    st.pop();
  }

  std::cout << "size: " << st.size() << std::endl;
  st.push(42);
  std::cout << "size: " << st.size() << std::endl;
}
