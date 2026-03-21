// Copyright hyamamot 2026
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


/*
sequence container : deque
*/

int main() {
  std::deque<int> d1;
  std::deque<int> d2 = {10, 20, 30, 40};
  for (int val : d2) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  std::deque<int> d;
  d.push_back(10);
  d.push_back(20);
  d.push_back(30);
  for (int val : d) {
    std::cout << val << " ";
  }
  std::cout << std::endl;
  d.push_front(30);
  d.push_front(20);
  d.push_front(10);
  for (int val : d) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  d.pop_back();
  d.pop_back();
  for (int val : d) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  d.pop_front();
  d.pop_front();
  for (int val : d) {
    std::cout << val << " ";
  }
  std::cout << std::endl;
}
